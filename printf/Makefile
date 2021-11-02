# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/02 15:11:13 by arendon-          #+#    #+#              #
#    Updated: 2021/11/02 15:32:51 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS		= -Wall -Wextra -Werror

SRCS		= init_reset_struct.c checkflags.c print_c_s.c ft_maximum_sizet.c \
				ft_minimum_sizet.c print_d.c printf_aux.c ft_putnstr_fd.c \
				checkconversion.c ft_printf.c

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar -crs $(NAME) *.o

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)