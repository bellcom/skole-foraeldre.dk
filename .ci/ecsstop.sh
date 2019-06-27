#!/bin/bash

PROJ_NAME=$1
PROJ_URL=$2
PROJ_STAGE=$3

source .ci/$PROJ_STAGE.conf
cat .ci/$PROJ_STAGE.conf

echo "$(date -Is) Starting..."
TASK_FAMILY="${PROJ_NAME}-${PROJ_URL}"
ECRTAG=$PROJ_URL
if [ $PROJ_URL == "develop" ] ; then 
  SERVICE_NAME=$PROJ_NAME
  TGNAME="ci-$PROJ_NAME"
else
  SERVICE_NAME="${PROJ_NAME}-${PROJ_URL}"
  TGNAME="ci-$PROJ_URL"
fi

#Stop service
aws ecs update-service --service ${SERVICE_NAME} --cluster ${CLUSTER_NAME} --region $AWSREGION --desired-count 0
aws ecs delete-service --service ${SERVICE_NAME} --cluster ${CLUSTER_NAME} --region $AWSREGION
#remove taskdef & revs
#for TASK_REV in $(aws ecs list-task-definitions | egrep ${PROJ_NAME} | egrep ${PROJ_URL} | sed 's/,//g'| sed 's/"//g' | sed 's/ //g' | awk -F: '{print $7}'); do
#aws ecs deregister-task-definition --task-definition ${TASK_FAMILY}:${TASK_REV} #(or full Amazon Resource Name (ARN) of the task definition to deregister. You must specify a revision.)
#done
#remove ELB listener rules :80 :443
for LISTENER in ${LISTENERS} 
do
  RULE_ARN=$(aws elbv2 describe-rules --listener-arn "${LISTENER}" --region $AWSREGION | egrep -B 5 "${TGNAME}" | egrep "RuleArn" | sed 's/,//g'| sed 's/"//g' | sed 's/ //g' | sed 's/RuleArn://g')
  if [ "${RULE_ARN:-0}" == 0 ]
  then
    echo "$(date -Is) There is no rule for $TGNAME in ELB: $LISTENER"
  else
    aws elbv2 delete-rule --rule-arn $RULE_ARN --region $AWSREGION
  fi
done
#remove target group
TG_ARN=$(aws elbv2 describe-target-groups --region $AWSREGION | egrep "${TGNAME}" | egrep "TargetGroupArn" | sed 's/,//g'| sed 's/"//g' | sed 's/ //g' | sed 's/TargetGroupArn://g')
if [ "${TG_ARN:-0}" == 0 ] ; then
  echo "$(date -Is) There is no TargetGroup: $TGNAME in ELB: $LISTENER"
else
  aws elbv2 delete-target-group --target-group-arn $TG_ARN --region $AWSREGION
fi
#remove ECR cicode repo
REPO_NAME="$CODEPREFIX$PROJ_NAME"
if [ $PROJ_URL == "develop" ] ; then 
  echo "$(date -Is) ${PROJ_URL} branch doesn't have STOP action (yet). Contact administrator to stop it for you."
  #aws ecr delete-repository --force --repository-name $REPO_NAME --region $AWSREGION
else
  aws ecr batch-delete-image --repository-name $REPO_NAME --image-ids imageTag=$PROJ_URL --region $AWSREGION
fi
echo "$(date -Is) Stop finished."
