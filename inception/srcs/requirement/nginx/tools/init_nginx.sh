#!/bin/bash

chown -R nginx:nginx /var/www
chmod -R 755 /var/www
exec nginx -g "daemon off;"