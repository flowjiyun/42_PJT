FROM alpine:3.16

WORKDIR /var/www/html

RUN apk update && \
	apk add php8-common php8-fpm php8-mysql php8-mysqli mysql-client wget && \
	addgroup -S nginx && adduser -S nginx -G nginx && \
	mkdir /app

RUN wget http://wordpress.org/latest.tar.gz && \
	tar -xzvf latest.tar.gz && \
	rm latest.tar.gz

COPY conf/wp-config.php ./wordpress
COPY conf/www.conf /etc/php8/php-fpm.d/www.conf
COPY tools/init_wordpress.sh /app
RUN chmod +x /app/init_wordpress.sh

EXPOSE 9000

ENTRYPOINT [ "sh", "/app/init_wordpress.sh" ]