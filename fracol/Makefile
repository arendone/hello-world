# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 16:03:57 by arendon-          #+#    #+#              #
#    Updated: 2022/01/14 17:59:45 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = frac_ol

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJS	= $(patsubst %.c, %.o, $(SRCS))

SRCS=	main.c 

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	
%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	rm -f $(NAME) $(OBJFILES)
	rmdir obj

.PHONY: clean