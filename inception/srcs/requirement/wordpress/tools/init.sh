# !/bin/sh
adduser -D nginx
chown -R nginx:nginx /var/www/wordpress
chmod -R 777 /var/www/wordpress/wordpress
php-fpm8 -F