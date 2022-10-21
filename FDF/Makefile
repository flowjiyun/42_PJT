# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 09:21:03 by jiyunpar          #+#    #+#              #
#    Updated: 2022/10/21 19:02:52 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all bonus clean fclean re

NAME = fdf

NAME_BONUS = fdf

SRC_DIR = ./src/
SRC_NAME = main.c check_file.c parse_map.c get_coordinate.c \
			init_struct.c \
			fdf_utils_1.c fdf_utils_2.c fdf_utils_3.c \
			linked_list_function_1.c linked_list_function_2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

# SRC_BONUS_DIR = ./src_bonus/
# SRC_BONUS_NAME = main_bonus.c pipex_bonus.c parse_path_bonus.c parse_arg_bonus.c get_dir.c error.c \
# 		ft_split.c pipex_utils.c make_heredoc.c \
# 		get_next_line.c get_next_line_utils.c \
#  		linked_list_function_1.c linked_list_function_2.c
# SRC_BONUS = $(addprefix $(SRC_BONUS_DIR),$(SRC_BONUS_NAME))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

MLX_LIB_DIR = ./mlx/
MLX_LIB = libmlx.dylib

# OBJ_BONUS_DIR = ./obj_bonus/
# OBJ_BONUS_NAME = $(SRC_BONUS_NAME:.c=.o)
# OBJ_BONUS = $(addprefix $(OBJ_BONUS_DIR),$(OBJ_BONUS_NAME))

INCLUDE := -I./include -I./mlx

CFLAGS := -Wall -Wextra -Werror -g
CFLAGS_DEBUG := -Wall -Wextra -Werror -g3 -fsanitize=address

all : all_check

all_check : $(OBJ) $(MLX_LIB)
		$(CC) $(CFLAGS) $(INCLUDE) -L./mlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $^
		touch $@
		
bonus : bonus_check

bonus_check : $(OBJ_BONUS)
		$(CC) $(CFLAGS) $(INCLUDE) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $^
		touch $@

clean :
		rm -rf $(OBJ_DIR)
		rm -rf $(OBJ_BONUS_DIR)
		make -C $(MLX_LIB_DIR) clean
		rm -f $(MLX_LIB)

fclean : clean
		rm -f $(NAME)
		rm -f all_check
		rm -f bonus_check

re :
		make fclean
		make all

$(MLX_LIB) : 
		make -C $(MLX_LIB_DIR)
		cp $(MLX_LIB_DIR)$(MLX_LIB) .

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		@mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) -I./mlx -c $< -o $@

$(OBJ_BONUS_DIR)%.o : $(SRC_BONUS_DIR)%.c
		mkdir -p $(OBJ_BONUS_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) -I./mlx -c $< -o $@
