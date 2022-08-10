# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 12:23:06 by jiyunpar          #+#    #+#              #
#    Updated: 2022/08/10 14:38:36 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

NAME := libftprintf.a

SRC_DIR = ./src/
SRC_NAME = ft_printf.c ft_printf_utils_1.c ft_printf_utils_2.c ft_printf_option_1.c \
			ft_printf_option_2.c
SRC = $(addprefix $(SRC_DIR),$(SRC_NAME))

OBJ_DIR = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_NAME))

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

INCLUDE := -I./include

CFLAGS := -Wall -Wextra -Werror

ARFLAGS := -rcus

all : $(NAME)

bonus : $(NAME)

clean :
		rm -rf $(OBJ_DIR)
		make -C $(LIB_DIR) clean

fclean : clean
		make -C $(LIB_DIR) fclean
		rm -f $(NAME)

re :
		make fclean
		make all

$(NAME) : $(OBJ)
		make -C $(LIB_DIR) re
		cp $(LIB) $(NAME)
		ar -q $@ $?

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
		mkdir -p $(OBJ_DIR)
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
