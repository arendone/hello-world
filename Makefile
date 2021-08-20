# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2021/08/20 17:21:19 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all: libft.a

libft.a: libft.o
	ar rcs libft.o -o libft.a
	
libft.o: libft.h ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_isprint.o
	gcc -c ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_isprint.o
	
ft_isalnum.o: ft_isalnum.c
	gcc -c ft_isalnum.c
	
ft_isalpha.o: ft_isalpha.c
	gcc -c ft_isalpha.c
	
ft_isascii.o: ft_isascii.c
	gcc -c ft_isascii.c
	
ft_isdigit.o: ft_isdigit.c
	gcc -c ft_isdigit.c
	
ft_isprint.o: ft_isprint.c
	gcc -c ft_isprint.c
	
ft_strlen.o: ft_strlen.c
	gcc -c ft_strlen.c
	
clean:
	rm -f *.o test123456