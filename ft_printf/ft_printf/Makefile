# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/10 12:23:06 by jiyunpar          #+#    #+#              #
#    Updated: 2022/08/16 11:21:45 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re bonus

NAME := libftprintf.a

SRC_MAN_DIR = ./src/
SRC_MAN_NAME = ft_printf.c ft_printf_check_arg.c ft_printf_calc_width.c \
			ft_printf_print_spec_1.c ft_printf_print_spec_2.c ft_printf_print_spec_3.c \
			ft_printf_print_width.c ft_printf_print_val.c
SRC_MAN = $(addprefix $(SRC_MAN_DIR),$(SRC_MAN_NAME))

SRC_BNS_DIR = ./src_bns/
SRC_BNS_NAME = ft_printf_bonus.c ft_printf_check_arg_bonus.c ft_printf_calc_width_bonus.c \
			ft_printf_print_spec_1_bonus.c ft_printf_print_spec_2_bonus.c ft_printf_print_spec_3_bonus.c \
			ft_printf_print_width_bonus.c ft_printf_print_val_bonus.c
SRC_BNS = $(addprefix $(SRC_BNS_DIR),$(SRC_BNS_NAME))

OBJ_DIR = ./obj/
OBJ_MAN_NAME = $(SRC_MAN_NAME:.c=.o)
OBJ_BNS_NAME = $(SRC_BNS_NAME:.c=.o)
OBJ_MAN = $(addprefix $(OBJ_DIR),$(OBJ_MAN_NAME))
OBJ_BNS = $(addprefix $(OBJ_DIR),$(OBJ_BNS_NAME))

LIB_DIR = ./libft/
LIB_NAME = ft
LIB = $(LIB_DIR)lib$(LIB_NAME).a

ifdef WITH_BONUS
		OBJ = $(OBJ_BNS)
		SRC_DIR = $(SRC_BNS_DIR)
else
		OBJ = $(OBJ_MAN)
		SRC_DIR = $(SRC_MAN_DIR)
endif

INCLUDE := -I./include

CFLAGS := -Wall -Wextra -Werror

ARFLAGS := -rcus

all : $(NAME)

bonus :
		make WITH_BONUS=1 all

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
