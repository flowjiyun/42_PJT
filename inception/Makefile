PHONY : all fclean re

all : .all_check

.all_check :
	docker compose -f ./srcs/docker-compose.yml build --no-cache
	touch $@

fclean :
	docker rmi $(docker images -a -q)
	rm -rf .all_check

re :
	make fclean
	make all