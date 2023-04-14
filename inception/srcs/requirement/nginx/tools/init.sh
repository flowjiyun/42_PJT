# !/bin/sh
nginx -g "daemon off;"
chown -R nginx:nginx /var/www/wordpress
chmod -R 755 /var/www/wordpress