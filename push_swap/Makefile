COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

NAME		= push_swap

SRC			= *.c

OBJ			= $(SRC:.c=.o)

$(NAME):
		$(COMPILER) $(FLAGS) -c $(SRC) -I./
		$(COMPILER) $(FLAGS) -o $(NAME) $(OBJ) -I./

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
