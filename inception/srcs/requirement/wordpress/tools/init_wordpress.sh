# !/bin/sh
wp core download --path=wordpress
cd wordpress
wp config create --dbname=$WORDPRESS_DB_NAME --dbuser=$WORDPRESS_DB_USER --dbpass=$WORDPRESS_DB_PASSWORD --dbhost=$WORDPRESS_DB_HOST
wp db create
wp db query "GRANT ALL ON \`$DB_NAME\`.* to '$DB_USER'@'%' IDENTIFIED BY '$DB_PASSWORD';"
wp db query "GRANT ALL ON \`$DB_NAME\`.* to '$DB_USER'@'localhost' IDENTIFIED BY '$DB_PASSWORD';"
wp core install --url=$WORDPRESS_URL --title=INCEPTION --admin_user=$WORDPRESS_ADMIN_USER --admin_password=$WORDPRESS_ADMIN_PASSWORD --admin_email=$WORDPRESS_ADMIN_EMAIL
chown -R nginx:nginx /var/www/html/wordpress
chmod -R 755 /var/www/html/wordpress
exec php-fpm8 -F