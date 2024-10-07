NAME = replace
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
SRC = main.cpp FileManager.cpp

all : $(NAME)

$(NAME) : $(SRC)
		$(CC) $(SRC) $(CFLAGS) -o $(NAME)

fclean :
		rm -rf $(NAME) *.replace

re : fclean all