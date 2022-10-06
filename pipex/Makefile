.PHONY : all clean fclean re

NAME = pipex

NAME_BONUS = pipex

SRC_DIR = ./src/
SRC_NAME = main.c parse_path.c parse_arg.c get_dir.c error.c \
		linked_list_function_1.c linked_list_function_2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

SRC_BONUS_DIR = ./src_bonus/
SRC_BONUS_NAME = main_bonus.c parse_path_bonus.c parse_arg_bonus.c get_dir.c error.c \
		linked_list_function_1.c linked_list_function_2.c
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR),$(SRC_BONUS_NAME))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

INCLUDE := -I./include

CFLAGS := -Wall -Wextra -Werror
CFLAGS_DEBUG := -Wall -Wextra -Werror -g -fsanitize=address

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
		make -C $(LIB_DIR) clean
		rm -rf $(OBJ_DIR)

fclean : clean
		make -C $(LIB_DIR) fclean
		rm -f $(NAME)

re :
		make fclean
		make all

$(NAME) : $(LIB) $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

$(LIB) :
		make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
