FROM alpine:3.17

WORKDIR /workspace
RUN apk update && \
	apk add dumb-init mariadb mariadb-client mariadb-server-utils && \
	rm -f /var/cache/apk/*


COPY ./tools/init_mariadb.sh .
RUN chmod -R 755 .

EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init","--","init_mariadb.sh"]