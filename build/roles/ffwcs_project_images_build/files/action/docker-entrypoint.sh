#!/usr/bin/env bash

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Changing owner of /var/www/html to www-data "
chown www-data:www-data /var/www/html

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Setting temporary index.html for when the data import is in progress"
mv /var/www/html/index.php /var/www/html/_index.php
echo "<html><head><title>Data import in progress</title></head><body><h1>Data import in progress</h1></body></html>" > /var/www/html/index.html

until mysql -uroot -ppassword -hmysql -e 'SELECT version()' 2>/dev/null; do
    echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Database connection not running, waiting 10 seconds"
    sleep 10
done

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Restoring original index.php"
rm /var/www/html/index.html
mv /var/www/html/_index.php /var/www/html/index.php

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Removing entries from cache table"
mysql -udrupal -pdrupal -hmysql -e 'TRUNCATE cache;' drupal

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Rebuilding registry"
gosu www-data:www-data drush rr

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Disable memcache_admin"
gosu www-data:www-data drush dis memcache_admin -y

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Set SOLR core URL"
gosu www-data:www-data drush solr-set-env-url --id=solr http://solr:8983/solr/core1

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Clearing all caches"
gosu www-data:www-data drush cc all

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Updating database"
gosu www-data:www-data drush updb

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Clearing all caches"
gosu www-data:www-data drush cc all

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Enabling stage-file-proxy"
gosu www-data:www-data drush pm-download stage_file_proxy
gosu www-data:www-data drush pm-enable --yes stage_file_proxy

echo "[INFO]["`date '+%Y-%m-%d %H:%M:%S'`"] Clearing all caches"
gosu www-data:www-data drush cc all
