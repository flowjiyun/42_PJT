# !/bin/sh
mariadbd --bootstrap < database_init.sql
mariadbd-safe -u root