# !/bin/sh
chown -R nginx:nginx /var/www/wordpress
chmod -R 755 /var/www/wordpress
exec php-fpm8 -F