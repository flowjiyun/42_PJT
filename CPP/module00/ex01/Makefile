.PHONY	= all clean fclean re

NAME	=	phonebook

SRC		=	$(wildcard *.cpp)

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

CFLAG	= 	-Wall -Wextra -Werror -std=c++98

all : .all_check

.all_check : $(OBJ)
	@$(CC) $(CFLAG) -o $(NAME) $^
	@touch $@

clean :
	@rm -rf $(OBJ)

fclean : 
	@make clean
	@rm -rf .all_check
	@rm -rf $(NAME)

re : 
	@make fclean
	@make all

%.o : %.cpp
	@$(CC) $(CFLAG) -c $< -o $@