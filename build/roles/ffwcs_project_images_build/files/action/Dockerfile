FROM drush/drush:8

COPY docker-entrypoint.sh /usr/local/bin/

ENV GOSU_VERSION 1.7
RUN dpkgArch="$(dpkg --print-architecture | awk -F- '{ print $NF }')" \
 && wget -O /usr/local/bin/gosu "https://github.com/tianon/gosu/releases/download/$GOSU_VERSION/gosu-$dpkgArch" \
 && chmod +x /usr/local/bin/gosu \
 && gosu nobody true

RUN mkdir -p /usr/share/drush/commands \
 && drush @none dl registry_rebuild-7.x --destination=/usr/share/drush/commands

WORKDIR /var/www/html

ENTRYPOINT [ "docker-entrypoint.sh" ]
