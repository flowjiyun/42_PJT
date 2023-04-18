FROM alpine:3.16

WORKDIR /workspace
RUN apk update && \
	apk add mariadb mariadb-client mariadb-server-utils && \
	rm -f /var/cache/apk/*


COPY ./tools/init_mariadb.sh .
RUN chmod -R 755 .

EXPOSE 3306

ENTRYPOINT ["sh", "init_mariadb.sh"]