# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 10:36:05 by jiyunpar          #+#    #+#              #
#    Updated: 2022/07/13 18:44:48 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = isalpha isdigit isalnum isascii isprint \
			toupper tolower strchr strrchr strlen strncmp \
			memset bzero memchr memcpy memcmp memmove \
			strnstr strlcpy strlcat atoi calloc strdup

SRC = $(addprefix ft_, $(addsuffix .c, $(SRC_NAME)))
OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g
ARFLAGS = -rc

all : $(NAME)

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

$(NAME) : $(OBJ)
		$(AR) $(ARFLAGS) $@ $?

%.o : %.c
		$(CC) $(CFLAGS) -c $< -o $@

.PHONY : all clean fclean re