FROM alpine:3.16

WORKDIR /var/www/wordpress

RUN apk update && apk add php8-common php8-fpm wget openrc
RUN rc-status && touch /run/openrc/softlevel
#RUN rc-update add php-fpm8 

RUN wget http://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz && rm latest.tar.gz

COPY conf/wp-config.php ./wordpress
COPY conf/www.conf /etc/php8/php-fpm.d/www.conf
COPY conf/index.html ./html
COPY tools/init.sh .


EXPOSE 9000

ENTRYPOINT [ "sh", "/var/www/wordpress/init.sh" ]