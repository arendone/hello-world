# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:03:57 by arendon-          #+#    #+#              #
#    Updated: 2022/02/01 18:21:19 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	main.c interaction.c colors.c mandelbrot.c read_arg.c ft_atof.c \
		julia.c

$(NAME): libft/libft.a $(OBJ)
	$(CC) $(OBJ) -Llibft -lft -L ./mlx/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -Ilibft -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)
	make -C libft clean

.PHONY: clean

libft/libft.a:
	make -C libft all

#quiero agregar todos los .o en carpeta obj, no olvides 
#cambiar tambien lo que hay en obj y el clean fclean,
#fclean: clean
#	rm -f $(NAME)
#	make -C libft fclean
