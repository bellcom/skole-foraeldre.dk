#!/bin/bash

PROJ_NAME=$1
PROJ_URL=$2
PROJ_STAGE=$3

source .ci/$PROJ_STAGE.conf
cat .ci/$PROJ_STAGE.conf

echo "$(date -Is) Starting..."
$(aws ecr get-login --no-include-email --region $AWSREGION | sed 's;https://;;g')
TASK_DEF_FILE=$TASKDEFSDIR/$TASKDEFNAME".json"
TASK_FAMILY="${PROJ_NAME}-${PROJ_URL}"
SERV_CONT=$SERVICECONT
echo "$(date -Is) TASKDEFSDIR: $TASKDEFSDIR CLUSTER: $CLUSTER_NAME Container: $SERV_CONT"

if [ $PROJ_STAGE == "deploydev" ] ; then 
  SERVICE_NAME=$PROJ_NAME
  BRANCH_DOCK_TAG="develop"
  TGNAME="ci-$PROJ_NAME"
else
  SERVICE_NAME="${PROJ_NAME}-${PROJ_URL}"
  BRANCH_DOCK_TAG=$PROJ_URL
  TGNAME="ci-$PROJ_URL"
fi
SERVICE_URL="${SERVICE_NAME}.demo.ffw-cs.com"
PROJ_CI_BRANCH_DB_NAME=$(echo "${SERVICE_NAME}" | sed 's/-/_/g')
TASK_QTY=$TASKNUM
if [ "${TASKDEFREV}" == "latest" ] ; then
  CURR_BUILD=$(aws ecs list-task-definitions --family-prefix $TASK_FAMILY --region $AWSREGION | jq -r '.taskDefinitionArns[]'  | sed 's/:/ /g' | awk '{print $7}' | sort -n | tail -1)
  #CURR_BUILD=$(aws ecs describe-services --region $AWSREGION --cluster $CLUSTER_NAME --service $SERVICE_NAME | jq -r '.services[0].deployments[0].taskDefinition' | sed 's/:/ /g' | awk '{print $7}') 
  BUILD_NUMBER=$(($CURR_BUILD+1))
else
  BUILD_NUMBER=$TASKDEFREV
fi
echo "$(date -Is) Task family: ${TASK_FAMILY} Task build: ${BUILD_NUMBER} Task QTY: ${TASK_QTY} Task def file: ${TASK_DEF_FILE}"
if [ "${TASKELB}" == "no" ]; then
  echo "$(date -Is) Not registering task ${TASK_FAMILY} in cluster ${CLUSTER_NAME} for public access in i ELB"
else
  echo "$(date -Is) Registering service to ELB i :80 and :443"
  #TASKELB=""
  DEPLMIN=$TASKMINP
  DEPLMAX=$TASKMAXP
  #TASKPLACEMENT="" 
  CONT_PORT=$SERVICEPORT
  #CONT_PORT=$(cat ${TASK_FAMILY}.json | egrep "containerPort" | awk '{print $2}' | sed 's/,$//')
  # Create new target-group if it doesn't exists
  TGEXISTS=$(aws elbv2 describe-target-groups --region $AWSREGION | egrep "${TGNAME}\"")
  if [ "${TGEXISTS:-0}" == 0  ] ; then
    echo "$(date -Is) Target group ${TGNAME} doesn't exists. creating it."
    aws elbv2 create-target-group --name ${TGNAME} --region $AWSREGION --protocol "$TG_PROTOCOL" --port ${CONT_PORT} --vpc-id "$AWS_VPC_ID" --health-check-protocol "$TG_HEALTH_CHECK_PROTOCOL" --health-check-port "$TG_HEALTH_CHECK_PORT" --health-check-path "$TG_HEALTH_CHECK_PATH" --health-check-interval-seconds ${TG_HEALTH_CHECK_INTERVAL_SEC} --health-check-timeout-seconds ${TG_HEALTH_CHECK_TIMEOUT_SEC} --healthy-threshold-count ${TG_HEALTHY_THRESHOLD_COUNT} --unhealthy-threshold-count ${TG_UNHEALTHY_THRESHOLD_COUNT} --matcher HttpCode="$TG_SUCCESS_CODE"
  fi
  TGARN=$(aws elbv2 describe-target-groups --names "${TGNAME}" --region $AWSREGION | egrep "TargetGroupArn" | awk '{print $2}' | sed 's/,$//' | sed 's/"//g')
  aws elbv2 modify-target-group-attributes --target-group-arn $TGARN --region $AWSREGION --attributes Key=deregistration_delay.timeout_seconds,Value=$TG_DEREG_DELAY
  #aws autoscaling attach-load-balancer-target-groups --auto-scaling-group-name "${SERVICE_NAME}" --target-group-arns "${TGARN} --region $AWSREGION "
  #create rule for 80 and 443 in elb "i"
  for LISTENER in ${LISTENERS} 
  do
    RULEEXISTS=$(aws elbv2 describe-rules --listener-arn "${LISTENER}" --region $AWSREGION | egrep "${SERVICE_URL}")
    if [ "${RULEEXISTS:-0}" == 0 ]
    then
      OCCUPRIO=$(aws elbv2 describe-rules --listener-arn "${LISTENER}" --region $AWSREGION | egrep "Priority")
      COUNTR=0
      while [ ${COUNTR} -lt 1000 ]; do
        let COUNTR=$COUNTR+1
        PRIOFREE=`echo ${OCCUPRIO} | egrep "$COUNTR"`
        if [ "${PRIOFREE:-0}" == 0 ]
        then
          PRIORITY=$COUNTR
          aws elbv2 create-rule --listener-arn ${LISTENER} --region $AWSREGION --conditions Field=host-header,Values="${SERVICE_URL}" --actions Type=forward,TargetGroupArn=${TGARN} --priority ${PRIORITY}
          break
        fi
      done 
    fi
  done
fi
echo "$(date -Is) Creating a new task definition of ${TASK_FAMILY} for this build: ${BUILD_NUMBER} . PHPinit will execute: ${DRUSHCMD}"

sed -e "s;%DOCKER_TAG%;${BUILD_NUMBER};g" -e "s,%DRUSH_CMD%,${DRUSHCMD},g" -e "s;%PROJ_DB_CONT_NAME%;${PROJ_CONT_DB_NAME};g" -e "s;%PHP_CONT_ECR_VER%;${PROJ_CONT_PHP_VER};g" -e "s;%AWS_ECR_REPO%;${ECRURLREPO};g" -e "s;%CODE_REPO_PREFIX%;${CODEPREFIX};g" -e "s;%DOCROOT_DIR%;${PROJ_DOCROOT_DIR};g" -e "s;%PROJECT_DB_NAME_CI%;${PROJ_CI_BRANCH_DB_NAME};g" -e "s;%SERV_FAMILY%;${TASK_FAMILY};g" -e "s;%CODE_BRANCH%;${BRANCH_DOCK_TAG};g" -e "s;%PROJECT_NAME_CI%;${PROJ_NAME};g" ${TASK_DEF_FILE} > ffw-cs-${TASK_FAMILY}-${BUILD_NUMBER}.json
aws ecs register-task-definition --family ${TASK_FAMILY} --region $AWSREGION --cli-input-json file://ffw-cs-${TASK_FAMILY}-${BUILD_NUMBER}.json
# Create new service if it doesn't exists (doublecheck on reloading inactive services)
SERVICEINACTIVE=$(aws ecs describe-services --services ${SERVICE_NAME} --cluster ${CLUSTER_NAME} --region $AWSREGION | egrep "status" | egrep "INACTIVE")
if [ "${SERVICEINACTIVE:-0}" == 0 ]; then
  SERVICEXISTS=$(aws ecs describe-services --services ${SERVICE_NAME} --cluster ${CLUSTER_NAME} --region $AWSREGION | egrep "desiredCount")
else
  SERVICEXISTS=""
fi
if [ "${SERVICEXISTS:-0}" == 0 ]; then
  echo "$(date -Is) Service ${SERVICE_NAME} from ${TASK_FAMILY} from container: ${SERV_CONT}"
  if [ "${TASKPLACEMENT}" == "no" ]; then
    aws ecs create-service --cluster ${CLUSTER_NAME} --service-name ${SERVICE_NAME} --task-definition ${TASK_FAMILY} --region $AWSREGION --load-balancers targetGroupArn="${TGARN}",containerName="${SERV_CONT}",containerPort=${CONT_PORT} --desired-count 0 # --role "arn:aws:iam::210458300759:role/ecsServiceRole" --deployment-configuration maximumPercent=$DEPLMAX,minimumHealthyPercent=$DEPLMIN
    #--placement-strategy type="spread",field="attribute:ecs.availability-zone" type="spread",field="instanceId"
  else
    aws ecs create-service --cluster ${CLUSTER_NAME} --service-name ${SERVICE_NAME} --task-definition ${TASK_FAMILY} --region $AWSREGION --load-balancers targetGroupArn="${TGARN}",containerName="${SERV_CONT}",containerPort=${CONT_PORT} --desired-count 0 --role "arn:aws:iam::210458300759:role/ecsServiceRole" --deployment-configuration maximumPercent=$DEPLMAX,minimumHealthyPercent=$DEPLMIN --placement-strategy $TASKPLACEMENT
  fi
fi
# Update the service with the new task definition and desired count
TASK_REVISION=$(aws ecs describe-task-definition --task-definition ${TASK_FAMILY} --region $AWSREGION | egrep "revision" | tr "/" " " | awk '{print $2}' | sed 's/"$//')
DESIRED_COUNT=$(aws ecs describe-services --services ${SERVICE_NAME} --cluster ${CLUSTER_NAME} --region $AWSREGION | egrep "desiredCount" | tail -1 | tr "/" " " | awk '{print $2}' | sed 's/,$//')
if [ "${DESIRED_COUNT:-0}" == "0" ]; then
    DESIRED_COUNT=$TASK_QTY
fi
echo "$(date -Is) rev: ${TASK_REVISION} count: ${DESIRED_COUNT}"
aws ecs update-service --cluster ${CLUSTER_NAME} --service ${SERVICE_NAME} --task-definition ${TASK_FAMILY}:${TASK_REVISION} --region $AWSREGION --desired-count ${DESIRED_COUNT} --health-check-grace-period-seconds ${ELBHCG_SECONDS}
echo "$(date -Is) Deploy finished."
