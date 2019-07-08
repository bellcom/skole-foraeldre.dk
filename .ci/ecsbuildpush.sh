#!/bin/bash

PROJ_NAME=$1
PROJ_URL=$2
PROJ_STAGE=$3
PROJ_SUBSTAGE=$4

source .ci/$PROJ_STAGE.conf
cat .ci/$PROJ_STAGE.conf

echo -e "\e[32m$(date -Is) Starting...\e[0m"

echo -e "\e[32m$(date -Is) Login to AWS\e[0m"
aws configure set default.region $AWSREGION
$(aws ecr get-login --no-include-email --region "$AWSREGION" | sed 's;https://;;g')
IMAGENAME="$CODEPREFIX$PROJ_NAME"
REPOSITORY_URL="$ECRURLREPO/$IMAGENAME"
IMAGE_URL="$REPOSITORY_URL:$PROJ_URL"
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
	sed -iE 's;base_url:.*$;base_url: '"$FULLURL"';g' $PROJ_BEHAT_LOC
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
		CWD=$(pwd)
		gem update --system
		#RUBYUSERPATH=$(gem environment | egrep "\- INSTALLATION DIRECTORY" | awk -F: '{print $2}' | sed 's/ //g')
		#echo -e "\e[32m$(date -Is) Ruby user path: $RUBYUSERPATH\e[0m"
		#export PATH=$PATH:$RUBYUSERPATH
		cd $BUILDSDIR/$PROJ_DOCROOT/$COMPASSCOMPILELOC
		bundle config --global silence_root_warning 1
		bundle install
		compass compile
		cd $CWD
		echo -e "\e[32m$(date -Is) Compiled the project's sass files into css (in $BUILDSDIR/$PROJ_DOCROOT/$COMPASSCOMPILELOC)\e[0m"
	else
		echo -e "\e[32m$(date -Is) ${PROJ_NAME} needs compass compile is set to: ${NEEDSCOMPASSCOMPILE}, so we are skipping it.\e[0m"
	fi
	CREATEECR=$(aws ecr create-repository --repository-name $IMAGENAME --region $AWSREGION | grep -v "RepositoryAlreadyExistsException")
	# TODO: also grep -v "CREATED" !!!
	if [ "${CREATEECR:-0}" == 0 ] ; then
		echo -e "\e[32m$(date -Is) Proceeding with build and push of ${IMAGE_URL}\e[0m"
		docker build -t $IMAGE_URL -f Dockerfile .
		docker push $IMAGE_URL
		echo -e "\e[32m$(date -Is) Build and push finished.\e[0m"
	else
		echo -e "\e[36m$(date -Is) Build and push FAILED. Erron on create ECR: ${CREATEECR}\e[0m"
		exit 1
	fi
elif [[ ${PROJ_SUBSTAGE} == "db" ]] ; then
	# Overwrite source db w/ newest and sanitize envar
	if [[ ${PROJ_CI_DB_SOURCE} == "" ]] ; then
		PROJ_CI_DB_SOURCEFILE=$(ls /storage/s3/sanedbbackups/${PROJ_NAME}/*-${PROJ_NAME}-sanitized.sql.gz | sort -drf | head -n 1)
		SANITIZEDBONLOAD="no"
	elif [[ ${PROJ_CI_DB_SOURCE} == "prod" ]] ; then
		PROJ_CI_DB_SOURCEFILE=$(ls /storage/s3/dbbackups/${PROJ_NAME}/*-${PROJ_NAME}_backup.sql.gz | sort -drf | head -n 1)
		SANITIZEDBONLOAD="yes"
	else
		PROJ_CI_DB_SOURCEFILE=$PROJ_CI_DB_SOURCE
		SANITIZEDBONLOAD=$SANITIZE_DB_ON_LOAD
	fi

	# check and create mysql container if missing
	echo -e "\e[32m$(date -Is) Loading database in $PROJ_CI_BRANCH_DB_NAME from $PROJ_CI_DB_SOURCEFILE\e[0m"
	CURRENTDB=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;" | grep $PROJ_CI_BRANCH_DB_NAME | grep -v "${PROJ_CI_BRANCH_DB_NAME}_" | grep -v "${PROJ_CI_BRANCH_DB_NAME}[A-Za-z0-9]")
	echo "Contens of CURRENTDB: $CURRENTDB"
	INSTANCEIP=$(curl http://169.254.169.254/latest/meta-data/local-ipv4)
	echo "IP: $INSTANCEIP DB: $CURRENTDB"
	if [[ "${LOCAL_DB_USED}" == "yes" ]]; then
		MARIACONTNAME="mariadbloc"
		MARIASTORAGE=/storage/mariadbloc
		WAITFORMARIA=60
		DBCONTBASEPULL="185836940016.dkr.ecr.eu-west-1.amazonaws.com/mariadb_10_special_cidb:latest"
		MARIACONTID=$(docker ps | grep $MARIACONTNAME | head -n1 | awk '{print $1}')
		if [ "${MARIACONTID:-0}" == 0 ]; then	
			DBCONTID=$(docker run --name $MARIACONTNAME --net=host -p $PROJ_CI_DB_HOST:3306:3306 -e MYSQL_ROOT_PASSWORD=$PROJ_CI_DB_ROOT -d $DBCONTBASEPULL)
			# temp disable persistence:  -v $MARIASTORAGE:/var/lib/mysql-freeze
			echo "MariaDB container was missing. Created container: $DBCONTID Sleeping for ${WAITFORMARIA} seconds now"
			sleep $WAITFORMARIA
		else
			DBCONTID=$MARIACONTID
			echo "MariaDB container is already there with ID: $MARIACONTID"
		fi
	elif [[ "${LOCAL_DB_USED}" == "no" ]]; then
		echo -e "\e[32m$(date -Is) Using non-local DB: $PROJ_CI_DB_HOST\e[0m"
	else
		echo -e "\e[36m$(date -Is) ERROR: Database is not set properly. You need either \"yes\" or \"no\" for contents of LOCAL_DB_USED. Contents: ${LOCAL_DB_USED}. Exiting....\e[0m"
		exit 1
	fi
	# Prepare for, and load DB
	if [ "${CURRENTDB:-0}" == 0 ]; then
		echo -e "\e[32m$(date -Is) There is no DB $PROJ_CI_BRANCH_DB_NAME in $PROJ_CI_DB_HOST:$PROJ_CI_DB_PORT Creating it...\e[0m"
		# create mysql db and user
		mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"CREATE DATABASE $PROJ_CI_BRANCH_DB_NAME;"
		mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"GRANT ALL PRIVILEGES ON $PROJ_CI_BRANCH_DB_NAME.* TO '$PROJ_CI_DB_USER'@'%' IDENTIFIED BY '$PROJ_CI_DB_PASS';"
		mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"FLUSH PRIVILEGES;"
		echo -e "\e[32m$(date -Is) User and DB added, \e[0m\e[5mloading\e[0m\e[32m database from $PROJ_CI_DB_SOURCEFILE (be patient please)\e[5m...\e[32m Tables before:\e[0m"
		mysql -u$PROJ_CI_DB_USER -p$PROJ_CI_DB_PASS -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT $PROJ_CI_BRANCH_DB_NAME -e"SHOW TABLES;"
		# Load database
		zcat $PROJ_CI_DB_SOURCEFILE | mysql -u$PROJ_CI_DB_USER -p$PROJ_CI_DB_PASS -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT $PROJ_CI_BRANCH_DB_NAME
		LOADRESULT=$?
		DBCREATED=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;" | grep $PROJ_CI_BRANCH_DB_NAME | grep -v "${PROJ_CI_BRANCH_DB_NAME}_" | grep -v "${PROJ_CI_BRANCH_DB_NAME}[A-Za-z0-9]")
		echo -e "\e[32m$(date -Is) Result from loading: $LOADRESULT\e[0m"
		echo -e "\e[32m$(date -Is) New database created: $DBCREATED\e[0m"
		if [[ "${SANITIZEDBONLOAD}" == "yes" ]]; then
			SETTFILEFORSANITIZE=/storage/efs/sanitize_db_sett.list
			USERMAILCOL="mail"
			USERPASSCOL="pass"
			projline=$(cat $SETTFILEFORSANITIZE | grep $PROJ_NAME | head -n 1)
			echo "$projline"
			arrline=($projline)
			MAILCHANGE="${arrline[2]}"
			PASSHASH="${arrline[3]}"
			# change email for all users
			mysql -u$PROJ_CI_DB_USER -p$PROJ_CI_DB_PASS -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"UPDATE $USERDATATABLE SET $USERMAILCOL = \"$MAILCHANGE\";" $PROJ_CI_BRANCH_DB_NAME
			# change passhash for all users
			mysql -u$PROJ_CI_DB_USER -p$PROJ_CI_DB_PASS -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"UPDATE $USERDATATABLE SET $USERPASSCOL = \"$PASSHASH\";" $PROJ_CI_BRANCH_DB_NAME
			echo -e "\e[32m$(date -Is) Mail and pass changed in $USERDATATABLE to $MAILCHANGE and default pass with hash: $PASSHASH , according $SETTFILEFORSANITIZE\e[0m"
		fi
		ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
		if [ "${LOADRESULT:-0}" == 0 ]; then
			echo -e "\e[32m$(date -Is) Database $PROJ_CI_BRANCH_DB_NAME imported. All databases now:\e[0m"
			echo -e "${ALLDBS}"
		else
			echo -e "\e[32m$(date -Is) Cannot import database. Error was:\e[0m"
			echo -e "${LOADRESULT}"
			echo -e "\e[32m$(date -Is) SHOW DATABASES result:\e[0m"
			echo -e "${ALLDBS}"
			echo -e "\e[32m$(date -Is) Stage failed, exiting...\e[0m"
			exit 1
		fi
	else
		DBEXISTS=$(echo "$CURRENTDB" | grep -v "$PROJ_CI_BRANCH_DB_NAME")
		ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
		DBTABLES=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT $PROJ_CI_BRANCH_DB_NAME -e"SHOW TABLES;")
		if [ "${DBEXISTS:-0}" == 0 ]; then
			echo -e "\e[32m$(date -Is) The database already exists. Clear it by manually running stop:*DB job if/when needed. Output:\e[0m"
			echo -e "${CURRENTDB}"
			echo -e "Continuing with the SAME database. All databases:"
			echo -e "\e[32m$(date -Is) The database $PROJ_CI_BRANCH_DB_NAME is left intact. All tables:\e[0m"
			echo -e "${DBTABLES}"
		else
			echo -e "\e[32m$(date -Is) Cannot import database . Error was:\e[0m"
			echo -e "${CURRENTDB}"
			echo -e "\e[32m$(date -Is) SHOW DATABASES result:\e[0m"
			echo -e "${ALLDBS}"
			echo -e "\e[32m$(date -Is) Stage failed, exiting...\e[0m"
			echo -e "\e[32m$(date -Is) SHOW TABLES result:\e[0m"
			echo -e "${DBTABLES}"
			exit 1
		fi
	fi
elif [[ ${PROJ_SUBSTAGE} == "dropdb" ]] ; then
	echo -e "\e[32m$(date -Is) Dropping DB: $PROJ_CI_BRANCH_DB_NAME\e[0m"
	DROPRESULT=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;")
	#mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;" || rm -r /storage/mysql/ffwcs/$PROJ_CI_BRANCH_DB_NAME/ && mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"DROP DATABASE $PROJ_CI_BRANCH_DB_NAME;"
	ALLDBS=$(mysql -uroot -p$PROJ_CI_DB_ROOT -h$PROJ_CI_DB_HOST -P$PROJ_CI_DB_PORT -e"SHOW DATABASES;")
	if [ "${DROPRESULT:-0}" == 0 ]; then
		echo -e "\e[32m$(date -Is) The database $PROJ_CI_BRANCH_DB_NAME is dropped. Databases now:\e[0m"
		echo -e "${ALLDBS}"
	else
		echo -e "\e[32m$(date -Is) Cannot drop database. Error was:\e[0m"
		echo -e "${DROPRESULT}"
		echo -e "\e[32m$(date -Is) Either stage failed or just the DB is already dropped. All databases:\e[0m"
		echo -e "${ALLDBS}"
		echo -e "\e[32mExiting...\e[0m"
		exit 1
	fi
else
	echo -e "\e[32m$(date -Is) You need to specify one of sub-stages: proj (for project build), db (for DB preparation) OR dropdb (for cleanup DB). Now you've specified: ${PROJ_SUBSTAGE}\e[0m"
fi
