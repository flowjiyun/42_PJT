.PHONY : all clean fclean re

NAME = pipex

NAME_BONUS = pipex

SRC_DIR = ./src/
SRC_NAME = main.c parse_path.c parse_arg.c get_dir.c error.c \
		ft_split.c pipex_utils.c \
		linked_list_function_1.c linked_list_function_2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

SRC_BONUS_DIR = ./src_bonus/
SRC_BONUS_NAME = main_bonus.c parse_path_bonus.c parse_arg_bonus.c get_dir.c error.c \
		ft_split.c pipex_utils.c make_heredoc.c \
		get_next_line.c get_next_line_utils.c \
 		linked_list_function_1.c linked_list_function_2.c
SRC_BONUS = $(addprefix $(SRC_BONUS_DIR),$(SRC_BONUS_NAME))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

OBJ_BONUS_DIR = ./obj_bonus/
OBJ_BONUS_NAME = $(SRC_BONUS_NAME:.c=.o)
OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR),$(OBJ_BONUS_NAME))

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

INCLUDE := -I./include

CFLAGS := -Wall -Wextra -Werror
CFLAGS_DEBUG := -Wall -Wextra -Werror -g3 -fsanitize=address

all : all_check

all_check : $(OBJ)
		touch $@
		$(CC) $(CFLAGS_DEBUG) $(INCLUDE) -o $(NAME) $^
		
bonus : bonus_check

bonus_check : $(OBJ_BONUS)
		touch $@
		$(CC) $(CFLAGS_DEBUG) $(INCLUDE) -o $(NAME_BONUS) $^

clean :
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_BONUS_DIR)

fclean : clean
		rm -f $(NAME)
		rm -f all_check
		rm -f bonus_check
		rm -f outfile
		rm -f here_doc

re :
		make fclean
		make all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS_DEBUG) $(INCLUDE) -c $< -o $@

$(OBJ_BONUS_DIR)%.o : $(SRC_BONUS_DIR)%.c
		mkdir -p $(OBJ_BONUS_DIR)
		$(CC) $(CFLAGS_DEBUG) $(INCLUDE) -c $< -o $@