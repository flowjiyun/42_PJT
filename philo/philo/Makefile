# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 09:21:03 by jiyunpar          #+#    #+#              #
#    Updated: 2023/01/18 13:57:47 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all bonus clean fclean re

NAME				:=	philo

SRC					:=	main check_input create_philo set_struct routine monitoring utils \
						print_status action
SRC_M				:=	$(addprefix src/, $(addsuffix .c, $(SRC)))

SRCS				:=	$(SRC_M)

OBJS				:=	$(SRCS:.c=.o)

LIBFT_DIR			=	./libft
LIBFT				=	$(LIBFT_DIR)/libft.a
INCLUDE				=	-I./include
CFLAGS				=	-Wall -Wextra -Werror -pthread
# CFLAGS				=	 -pthread -fsanitize=thread -g
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
	@$(CC) $(CFLAGS) $(INCLUDE) -L$(LIBFT_DIR) -lft -o $(NAME) $^
	@touch $@

clean	:
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean	:
	@make clean
	@rm -f .all_check
	@rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re :
	@make fclean
	@make all
