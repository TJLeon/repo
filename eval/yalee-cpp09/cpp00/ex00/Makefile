NAME = megaphone
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = megaphone.cpp

all : $(NAME)

$(NAME) : $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

fclean :
		rm -rf $(NAME)

re : fclean all