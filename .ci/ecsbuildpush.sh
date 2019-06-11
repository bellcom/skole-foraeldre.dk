#!/bin/bash

PROJ_NAME=$1
PROJ_URL=$2
PROJ_STAGE=$3
PROJ_SUBSTAGE=$4

source .ci/$PROJ_STAGE.conf
cat .ci/$PROJ_STAGE.conf

echo -e "\e[32m$(date -Is) Starting...\e[0m"

#ADD BRANCHTAG
VERTAG=$PROJ_URL

echo -e "\e[32m$(date -Is) Login to AWS\e[0m"
aws configure set default.region $AWSREGION
$(aws ecr get-login --no-include-email --region "$AWSREGION" | sed 's;https://;;g')
IMAGENAME="$CODEPREFIX$PROJ_NAME"
REPOSITORY_URL="$ECRURLREPO/$IMAGENAME"
IMAGE_URL="$REPOSITORY_URL:$VERTAG"
CIPHPSETTFILE="$BUILDSDIR/$PROJ_DOCROOT/sites/default/ci.settings.php"

echo -e "\e[32m$(date -Is) Current contents: $(ls -lah)\e[0m"
if [[ $PROJ_URL == "develop" ]] ; then
	FULLURL="${URLSCHEME}://${PROJ_NAME}${URLDOMAIN}"
	PROJ_CI_BRANCH_DB_NAME=$(echo "${PROJ_NAME}" | sed 's/-/_/g')
	echo -e "\e[32m$(date -Is) DB requested: ${PROJ_CI_DB_NAME}, but we're on develop, so we build with DB name: ${PROJ_CI_BRANCH_DB_NAME}\e[0m"
else
	FULLURL="${URLSCHEME}://${PROJ_NAME}-${PROJ_URL}${URLDOMAIN}"
	PROJ_CI_BRANCH_DB_NAME=$(echo "${PROJ_NAME}-${PROJ_URL}" | sed 's/-/_/g')
	echo -e "\e[32m$(date -Is)DB requested: ${PROJ_CI_DB_NAME}, but we'll deploy with name: ${PROJ_CI_BRANCH_DB_NAME}\e[0m"
fi

echo -e "\e[32m$(date -Is) This branch will build and push docker image: ${IMAGE_URL} with DB: ${PROJ_CI_BRANCH_DB_NAME}\e[0m"
echo -e "\e[32m$(date -Is) URL built: ${FULLURL}  Link is generated on deploy, and can be found in gitlab CI/CD>Environments. Just expand \"feature/\" environments group\e[0m"

# FIX DB NAME AND ADD IT TO CI.SETTINGS.PHP
if [[ ${PROJ_SUBSTAGE} == "proj" ]] ; then
	# ADD BASE_URL IN TESTS/BEHAT/BEHAT.YML
	BEHAT_YML="tests/behat/behat.yml"
	sed -iE 's;base_url:.*$;base_url: '"$FULLURL"';g' $BEHAT_YML
	# ADD DB NAME TO CI.SETTINGS.PHP
	sed -i "s;__DB_NAME__;$PROJ_CI_BRANCH_DB_NAME;g" $CIPHPSETTFILE
	if [[ ${NEEDSCOMPOSERINSTALL} == "yes" ]] ; then
		if [[ $COMPOSERWORKDIR == "top" ]] ; then
			COMPOSERBUILDWORKDIR=$BUILDSDIR
		elif [[ $COMPOSERWORKDIR == "index" ]] ; then
			COMPOSERBUILDWORKDIR=$BUILDSDIR/$PROJ_DOCROOT
		else
			COMPOSERBUILDWORKDIR=$BUILDSDIR/$COMPOSERWORKDIR
		fi
		php composer.phar self-update $COMPOSERVERSION
		php composer.phar --working-dir=$COMPOSERBUILDWORKDIR --no-interaction --no-dev install
		echo -e "\e[32m$(date -Is) Composer install (version $COMPOSERVERSION) is executed in $COMPOSERBUILDWORKDIR\e[0m"
	else
		echo -e "\e[32m$(date -Is) ${PROJ_NAME} needs composer install is set to: ${NEEDSCOMPOSERINSTALL}, so we are skipping it.\e[0m"
	fi
	if [[ ${NEEDSCOMPASSCOMPILE} == "yes" ]] ; then
		compass compile $BUILDSDIR/$PROJ_DOCROOT/$COMPASSCOMPILELOC
		echo -e "\e[32m$(date -Is) Compiled the project's sass files into css\e[0m"
	else
		echo -e "\e[32m$(date -Is) ${PROJ_NAME} needs compass compile is set to: ${NEEDSCOMPASSCOMPILE}, so we are skipping it.\e[0m"
	fi
	aws ecr create-repository --repository-name $IMAGENAME --region $AWSREGION
	docker build -t $IMAGE_URL -f Dockerfile .
	docker push $IMAGE_URL
	# TODO: Check if DB exists to deploy only if missing (the first time)
	echo -e "\e[32m$(date -Is) Build and push finished.\e[0m"
elif [[ ${PROJ_SUBSTAGE} == "db" ]] ; then
	# TODO: Overwrite db w/ newest (manual job update)
	if [[ ${PROJ_CI_DB_SOURCE} == "" ]] ; then
		PROJ_CI_DB_SOURCEFILE=$(ls /storage/s3/sanedbbackups/${PROJ_NAME}/*-${PROJ_NAME}-sanitized.sql.gz | sort -drf | head -n 1)
	else
		PROJ_CI_DB_SOURCEFILE=$PROJ_CI_DB_SOURCE
	fi
	echo -e "\e[32m$(date -Is) Loading database in $PROJ_CI_BRANCH_DB_NAME from$PROJ_CI_DB_SOURCEFILE\e[0m"
	CREATERESULT=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"CREATE DATABASE $PROJ_CI_BRANCH_DB_NAME;")
	if [ "${CREATERESULT:-0}" == 0 ]; then
		# create mysql user
		mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"GRANT ALL PRIVILEGES ON $PROJ_CI_BRANCH_DB_NAME.* TO '$PROJ_CI_DB_USER'@'%' IDENTIFIED BY '$PROJ_CI_DB_PASS';"
		mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"FLUSH PRIVILEGES;"
		# Load database
		LOADRESULT=$(zcat $PROJ_CI_DB_SOURCEFILE | mysql -u$PROJ_CI_DB_USER -p$PROJ_CI_DB_PASS -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT $PROJ_CI_BRANCH_DB_NAME)
		ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
		if [ "${LOADRESULT:-0}" == 0 ]; then
			echo -e "\e[32m$(date -Is) Database $PROJ_CI_BRANCH_DB_NAME loaded. All databases now:\e[0m"
			echo -e "${ALLDBS}"
		else
			echo -e "\e[32m$(date -Is) Cannot load database. Error was:\e[0m"
			echo -e "${LOADRESULT}"
			echo -e "\e[32m$(date -Is) SHOW DATABASES result:\e[0m"
			echo -e "${ALLDBS}"
			echo -e "\e[32m$(date -Is) Stage failed, exitting...\e[0m"
			exit 1
		fi
	else
		DBEXISTS=$(echo "$CREATERESULT" | grep "database exists")
		ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
		DBTABLES=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT $PROJ_CI_BRANCH_DB_NAME -e"SHOW TABLES;")
		if [ "${DBEXISTS:-0}" == 0 ]; then
			echo -e "\e[32m$(date -Is) Cannot load database, not because it exists. Error was:\e[0m"
			echo -e "${CREATERESULT}"
			echo -e "\e[32m$(date -Is) SHOW DATABASES result:\e[0m"
			echo -e "${ALLDBS}"
			echo -e "\e[32m$(date -Is) Stage failed, exitting...\e[0m"
			echo -e "\e[32m$(date -Is) SHOW TABLES result:\e[0m"
			echo -e "${DBTABLES}"
			exit 1
		else
			echo -e "\e[32m$(date -Is) Cannot load database, because it already exists. Clear it by manually runing stop:*DB job if/when needed. Exact error was:\e[0m"
			echo -e "${CREATERESULT}"
			echo -e "Continuing with the SAME database. All databases:"
			echo -e "\e[32m$(date -Is) Database $PROJ_CI_BRANCH_DB_NAME exists is left intact. All tables:\e[0m"
			echo -e "${DBTABLES}"
		fi
	fi
elif [[ ${PROJ_SUBSTAGE} == "dropdb" ]] ; then
	echo -e "\e[32m$(date -Is) Droping DB: $PROJ_CI_BRANCH_DB_NAME\e[0m"
	DROPRESULT=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;")
	#mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;" || rm -r /storage/mysql/ffwcs/$PROJ_CI_BRANCH_DB_NAME/ && mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;"
	ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
	if [ "${DROPRESULT:-0}" == 0 ]; then
		echo -e "\e[32m$(date -Is) Database $PROJ_CI_BRANCH_DB_NAME is dropped. Databases now:\e[0m"
		echo -e "${ALLDBS}"
	else
		echo -e "\e[32m$(date -Is) Cannot drop database. Error was:\e[0m"
		echo -e "${DROPRESULT}"
		echo -e "\e[32m$(date -Is) Either stage failed or just the DB is already dropped. All databases:\e[0m"
		echo -e "${ALLDBS}"
		echo -e "\e[32mExitting...\e[0m"
		exit 1
	fi
else
	echo -e "\e[32m$(date -Is) You need to specify one of substages: proj (for project build), db (for DB preparation) OR dropdb (for cleanup DB). Now you've specified: ${PROJ_SUBSTAGE}\e[0m"
fi
