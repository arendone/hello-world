# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radelwar <radelwar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/11 10:58:50 by coder             #+#    #+#              #
#    Updated: 2022/01/03 16:26:20 by radelwar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account

CC = c++
CFLAGS = -Wall -Wextra -Werror

SRC =	Account.cpp	\
		tests.cpp

OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(addprefix , $(SRC))
		$(CC) $(CFLAGS) -c $^
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all