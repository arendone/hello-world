# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/08 20:52:36 by coder             #+#    #+#              #
#    Updated: 2021/12/08 21:40:08 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SDIR = src
SRC =	megaphone.cpp

CC = c++
CFLAGS = -Wall -Wextra -Werror

ODIR = obj
OBJ = $(patsubst %.cpp, %.o, $(SRC))

all: $(NAME)

$(NAME): $(addprefix $(SDIR)/, $(SRC))
	@echo start compiling $(NAME)
	$(CC) $(CFLAGS) -c $^
	mkdir -p $(ODIR)
	mv $(OBJ) $(ODIR)
	$(CC) $(CFLAGS) $(addprefix $(ODIR)/, $(OBJ)) -o $(NAME)
	@echo compiled $(NAME)

clean:
	rm -rf $(ODIR)
	@echo removed $(ODIR)

fclean: clean
	rm -rf $(NAME)
	@echo removed $(NAME)

re: fclean all
