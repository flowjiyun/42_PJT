# !/bin/sh
if [ -d "/run/myspld" ]; then
		echo "mysqld already present, skip creation"
		chown -R mysql:mysql /run/mysqld
else
		echo "mysqld not found, creating..."
		mkdir -p /run/mysqld
		chown -R mysql:mysql /run/mysqld
fi

if [ -d "/var/lib/mysql/mysql" ]; then
		echo "mysql directory already present, skip creation"
		chown -R mysql:mysql /var/lib/mysql
else
		echo "mysql data directory not found, creating..."
		chown -R mysql:mysql /var/lib/mysql
		mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null

		MYSQL_DATABASE=${MYSQL_DATABASE:-""}
		MYSQL_USER=${MYSQL_USER:-""}
		MYSQL_PASSWORD=${MYSQL_PASSWORD:-""}

		tfile=`mktemp`
		if [ ! -f "$tfile" ]; then
			return 1
		fi

		cat << EOF > $tfile
USE mysql;
FLUSH PRIVILEGES;
GRANT ALL ON *.* TO 'root'@'%' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
GRANT ALL ON *.* TO 'root'@'localhost' identified by '$MYSQL_ROOT_PASSWORD' WITH GRANT OPTION;
SET PASSWORD FOR 'root'@'localhost'=PASSWORD('${MYSQL_ROOT_PASSWORD}');
DROP DATABASE IF EXISTS test;
FLUSH PRIVILEGES;
EOF
		# echo "Creating database : $MYSQL_DATABASE"
		# echo "CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\` CHARACTER SET utf8 COLLATE utf8_general_ci;" >> $tfile
		# echo "Creating User : $MYSQL_USER"
		# echo "GRANT ALL ON \`$MYSQL_DATABASE\`.* to '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';" >> $tfile
		# echo "GRANT ALL ON \`$MYSQL_DATABASE\`.* to '$MYSQL_USER'@'localhost' IDENTIFIED BY '$MYSQL_PASSWORD';" >> $tfile

		/usr/bin/mysqld --user=mysql --bootstrap --verbose=0 --skip-name-resolve --skip-networking=0 < $tfile
		rm -f $tfile
fi

exec /usr/bin/mysqld --user=mysql --console --skip-name-resolve --skip-networking=0