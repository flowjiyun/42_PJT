# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 09:21:03 by jiyunpar          #+#    #+#              #
#    Updated: 2023/01/26 20:22:54 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all bonus clean fclean re

NAME				:=	cub3D

PARSE_MAP			:=	get_array_map_from_file get_map_data
PARSE_MAP_M			:=	$(addprefix src/parse_map/, $(addsuffix .c, $(PARSE_MAP)))

MAIN				:=	main
MAIN_M				:=	$(addprefix src/, $(addsuffix .c, $(MAIN)))

SRCS				:=	$(PARSE_MAP_M) $(MAIN_M)

OBJS				:=	$(SRCS:.c=.o)

LIBFT_DIR			=	./libft
# LIBFT				=	$(LIBFT_DIR)/libft.a

MLX_DIR				=	./mlx/
# MLX_LIB				=	libmlx.dylib

LIB_DIR				=	-L$(LIBFT_DIR) -L$(MLX_DIR)
LIB					= 	-lft -lmlx

INCLUDE				=	-I./include -I$(MLX_DIR) -I$(LIBFT_DIR)

CFLAGS				=	-Wall -Wextra -Werror

%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all	: .all_check

debugs	:
	make DEBUG=2

debug	:
	make DEBUG=1

ifeq ($(DEBUG), 1)
    CFLAGS	+=	-g3
endif
ifeq ($(DEBUG), 2)
    CFLAGS	+=	-g3 -fsanitize=address
endif

.all_check	: $(OBJS)
	@make -C $(LIBFT_DIR) re
	@make -C $(MLX_DIR)
#	@$(CC) $(CFLAGS) $(INCLUDE) $(LIB_DIR) $(LIB) \
			-framework OpenGL -framework AppKit -o $(NAME) $^
	@$(CC) $(CFLAGS) $(LIB_DIR) $(LIB) -o $(NAME) $^
	@install_name_tool -change libmlx.dylib @executable_path/${MLX_DIR}/libmlx.dylib ${NAME}
	@touch $@

clean	:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean

fclean	:
	@make clean
	@rm -f .all_check
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re :
	@make fclean
	@make all