FROM alpine:3.6

VOLUME [ "/var/www/html" ]
ADD . /var/www/html

RUN chown 33:33 /var/www/html \
 && mv /var/www/html/docker-entrypoint.sh /usr/local/bin/docker-entrypoint.sh \
 && chmod ugo+x /usr/local/bin/docker-entrypoint.sh

ENTRYPOINT [ "docker-entrypoint.sh" ]
