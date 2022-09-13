# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 14:46:54 by jiyunpar          #+#    #+#              #
#    Updated: 2022/09/13 16:27:07 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

NAME := push_swap

SRC_DIR = ./src/
SRC_NAME = main.c push_swap_utils_1.c push_swap_utils_2.c push_swap_function.c \
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
		$(CC) $(CFLAGS) -o $@ $^

$(LIB) :
		make -C $(LIB_DIR) all

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
