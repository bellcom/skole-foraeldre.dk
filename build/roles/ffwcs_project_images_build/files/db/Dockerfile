FROM 185836940016.dkr.ecr.eu-west-1.amazonaws.com/mariadb_10_main:latest

ENV MYSQL_DATABASE="drupal" \
    MYSQL_PASSWORD="drupal" \
    MYSQL_USER="drupal" \
    MYSQL_ROOT_PASSWORD="password"

COPY ./db.sql.gz /docker-entrypoint-initdb.d/db.sql.gz

VOLUME [ "/var/lib/mysql" ]
