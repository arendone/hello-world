# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2021/09/02 14:55:33 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar -crs $(NAME) *.o 

clean: 
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
