FROM alpine:3.16

WORKDIR /var/www/html

RUN apk update && apk add nginx openssl

RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=KO/ST=State/L=City/O=Organization/OU=Department/CN=localhost"
RUN mkdir /app
COPY ./conf/nginx.conf /etc/nginx/http.d
COPY ./conf/index.html .
COPY ./tools/init_nginx.sh /app
RUN chmod +x /app/init_nginx.sh

EXPOSE 443

ENTRYPOINT [ "sh", "/app/init_nginx.sh" ]
