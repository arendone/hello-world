# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/23 01:57:49 by arendon-          #+#    #+#              #
#    Updated: 2022/01/05 14:54:08 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	check_string_argv.c \
		errorsandfree.c \
		init_push.c \
		main_pushswap.c \
		operations_s.c \
		operations_p.c \
		operations_r.c \
		operations_rr.c \
		small_stack.c \
		sort.c \
		chunk.c \
		algorithm_utils.c 

%.o: %.c
	$(CC) $(FLAGS) -Ilibft -c $< -o $@

all: $(NAME)

$(NAME): libft/libft.a $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Llibft -lft -o $(NAME) 

clean:
	rm -f *.o
	rm -f *.out
	make -C libft clean

fclean: clean
	make -C libft fclean	
	rm -f $(NAME)

re: fclean $(NAME)
	
libft/libft.a:
	make -C libft all
