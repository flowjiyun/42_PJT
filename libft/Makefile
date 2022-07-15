# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiyunpar <jiyunpar@student.42seou.kr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/13 10:36:05 by jiyunpar          #+#    #+#              #
#    Updated: 2022/07/15 20:12:03 by jiyunpar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_NAME = isalpha isdigit isalnum isascii isprint \
			toupper tolower strchr strrchr strlen strncmp \
			memset bzero memchr memcpy memcmp memmove \
			strnstr strlcpy strlcat atoi calloc strdup \
			substr strjoin strtrim split itoa strmapi \
			striteri putchar_fd putstr_fd putendl_fd putnbr_fd \
			lstnew lstadd_front lstsize lstlast lstadd_back lstdelone \
			lstclear lstiter lstmap

#SRC_NAME_BONUS = lstnew


SRC = $(addprefix ft_, $(addsuffix .c, $(SRC_NAME)))
#SRC_BONUS = $(addprefix ft_, $(addsuffix .c, $(SRC_NAME_BONUS)))
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
		$(CC) $(CFLAGS) -I libft.h -c $< -o $@

.PHONY : all clean fclean re