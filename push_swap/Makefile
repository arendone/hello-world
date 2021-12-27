# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 01:57:49 by arendon-          #+#    #+#              #
#    Updated: 2021/12/27 19:24:41 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC= play1.c operations.c sort.c sort2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
#	cp ./libft/libft.a $(NAME)
	$(CC) -L./libft -lft -I./libft $(FLAGS) $(SRC) -o $(NAME)
#ar -crs $(NAME) $(OBJ)

clean:
	rm -f *.o
	cd ./libft && make clean
	
fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean
	
re: fclean all
