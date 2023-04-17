# !/bin/sh
chown -R nginx:nginx /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress
exec php-fpm8 -F