CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow -Wno-shadow
RM = rm -f
SOURCES = ./main.cpp
HEADER = ./whatever.hpp
NAME = template

#build everything
all: $(NAME)

#creates programm
$(NAME): $(SOURCES) $(HEADER)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

#removes executable
clean:
	$(RM) $(NAME)

#removes executable and rebuild it
re: clean all
