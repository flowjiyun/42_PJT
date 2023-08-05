FROM alpine:3.17

WORKDIR /var/www/html

RUN apk update && \
	apk add php php8-common php8-fpm php8-mysqli php8-phar php8-mbstring mariadb-client wget && \
	addgroup -S nginx && adduser -S nginx -G nginx && \
	mkdir /app

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
	chmod +x wp-cli.phar && \
	mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php8/php-fpm.d/www.conf
COPY tools/init_wordpress.sh /app
RUN chmod +x /app/init_wordpress.sh

EXPOSE 9000

ENTRYPOINT [ "sh", "/app/init_wordpress.sh" ]