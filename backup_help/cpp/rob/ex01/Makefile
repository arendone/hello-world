# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: coder <coder@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/09 20:01:07 by coder             #+#    #+#              #
#    Updated: 2021/12/11 20:36:42 by coder            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = myphone

SRC =	Phonebook.cpp	\
		Contact.cpp	\
		main.cpp

SDIR = src

OBJ = $(patsubst %.cpp, %.o, $(SRC))
ODIR = obj

CC = c++
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(addprefix $(SDIR)/, $(SRC))
		@$(CC) $(CFLAGS) -c $^
		@mkdir -p $(ODIR)
		@mv $(OBJ) $(ODIR)
		@$(CC) $(CFLAGS) $(addprefix $(ODIR)/, $(OBJ)) -o $(NAME)
		@echo $(NAME) compiled

clean:
		@rm -rf $(ODIR)
		@echo $(ODIR) removed

fclean: clean
		@rm -rf $(NAME)
		@echo $(NAME) removed

re: fclean all