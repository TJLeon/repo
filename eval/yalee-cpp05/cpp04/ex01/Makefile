NAME = morepolymorph

SRC = main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

fclean :
	rm -f $(NAME)

re : fclean all