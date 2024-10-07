NAME = btc

SRC = main.cpp BitcoinExchange.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

fclean :
	rm -f $(NAME)

re : fclean all