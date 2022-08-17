.POHNY : all clean fclean re

NAME = get_next_line.a
src = get_next_line_bonus.c get_next_line_utils_bonus.c
obj = $(src:.c=.o)

all : $(NAME)

clean :
		rm -f %.o
fclean : clean
		rm -f %.a
re :
	make fclean
	make all

$(NAME) : $(obj)
		ar -rcus $@ $?