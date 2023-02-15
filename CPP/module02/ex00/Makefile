.PHONY	= all clean fclean re

NAME	=	ex00

SRC		=	$(wildcard *.cpp)

OBJ		=	$(SRC:.cpp=.o)

CC		=	c++

CFLAG	= 	-Wall -Wextra -Werror

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