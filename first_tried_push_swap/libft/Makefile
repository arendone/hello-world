# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arendon- <arendon-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/20 16:20:05 by arendon-          #+#    #+#              #
#    Updated: 2021/11/05 11:32:03 by arendon-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_minimum_sizet.c ft_maximum_sizet.c ft_putnstr_fd.c

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

all: $(NAME) bonus

$(NAME):
	gcc $(CFLAGS) -c $(SRC)
	ar -crs $(NAME) *.o

clean:
	rm -f *.o
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus:
	gcc $(CFLAGS) -c $(BONUS)
	ar -crs $(NAME) *.o 
