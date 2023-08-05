FROM alpine:3.17

WORKDIR /var/www/html

RUN apk update && apk add dumb-init nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=KO/ST=State/L=City/O=Organization/OU=Department/CN=localhost"
RUN mkdir /app
COPY ./conf/nginx.conf /etc/nginx/http.d
COPY ./tools/init_nginx.sh /app
RUN chmod +x /app/init_nginx.sh

EXPOSE 443

ENTRYPOINT [ "/usr/bin/dumb-init", "--", "/app/init_nginx.sh" ]
