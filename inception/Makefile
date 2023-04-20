.PHONY : all fclean re

all : .all_check

.all_check :
	docker compose -f ./srcs/docker-compose.yml build --no-cache
	touch $@

fclean :
	docker rmi mariadb:v1 wordpress:v1 nginx:v1
	rm -rf .all_check

re :
	make fclean
	make all