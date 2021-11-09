# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:11:13 by arendon-          #+#    #+#              #
#    Updated: 2021/11/09 16:00:11 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC= init_reset_struct.c checkflags.c print_c_s.c \
print_d.c printf_aux.c checkconversion.c print_u.c \
print_x.c print_upperX.c print_p.c ft_printf.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar -crs $(NAME) $(OBJ)

clean:
	rm -f *.o
	cd ./libft && make clean
	
fclean: clean
	rm -f $(NAME)
	cd ./libft && make fclean
	
re: fclean all

bonus: $(OBJ)
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar -crs $(NAME) $(OBJ)