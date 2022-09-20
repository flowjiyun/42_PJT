# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyun <jiyun@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:46:54 by jiyunpar          #+#    #+#              #
#    Updated: 2022/09/20 22:09:54 by jiyun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME := push_swap

SRC_DIR = ./src/
SRC_NAME = main.c push_swap.c push_swap_utils_1.c push_swap_utils_2.c push_swap_function.c \
		sort_stack_a.c sort_stack_b.c \
		linked_list_function_1.c linked_list_function_2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

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
		$(CC) $(CFLAGS_DEBUG) -o $@ $^

$(LIB) :
		make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS_DEBUG) $(INCLUDE) -c $< -o $@
