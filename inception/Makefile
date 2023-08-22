.PHONY : all build clean fclean re

all : .all_check

.all_check :
	docker compose -f ./srcs/docker-compose.yml up
	touch $@

build: 
	docker compose -f ./srcs/docker-compose.yml build --no-cache

clean:
	docker compose -f ./srcs/dokcer-compose.yml down

fclean :
	make clean
	docker rmi -f mariadb:v1 wordpress:v1 nginx:v1
	rm -rf .all_check

re :
	make fclean
	make all
