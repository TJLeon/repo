NAME = phonebook
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp contact.cpp phonebook.cpp

all : $(NAME)

$(NAME) : $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

fclean :
		rm -rf $(NAME)

re : fclean all