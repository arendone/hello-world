# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 19:33:19 by arendon-          #+#    #+#              #
#    Updated: 2021/08/20 19:46:36 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = test_toupperlower

SRC = test_toupperlower.c 

all = $(NAME)

$(NAME): $(NAME).o header.h ft_tolower.o ft_toupper.o
	gcc $(SRC) ft_tolower.o ft_toupper.o -o $(NAME)
	
ft_tolower.o: ft_tolower.c header.h
	gcc -c ft_tolower.c
	
ft_toupper.o: ft_toupper.c header.h
	gcc -c ft_toupper.c
