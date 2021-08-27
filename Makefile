# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2021/08/27 15:18:21 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \

all: $(NAME)

$(NAME):
	gcc  -Wall -Werror -Wextra -c $(SRC)
	ar -crs $(NAME) *.o 

clean: 
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

