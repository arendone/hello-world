# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:03:57 by arendon-          #+#    #+#              #
#    Updated: 2022/01/21 12:23:45 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = frac_ol

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	main.c 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)

.PHONY: clean

#quiero agregar todos los .o en carpeta obj, no olvides 
#cambiar tambien lo que hay en obj y el clean fclean