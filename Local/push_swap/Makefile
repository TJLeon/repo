COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

NAME		= push_swap

SRC			= push_swap.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_list_init.c \
				ft_list_utils.c \
				ft_radix_sort.c \
				ft_stack_rot.c \
				ft_str_to_list.c \
				ft_list_to_index.c \
				ft_parse_input.c \
				ft_stack_push.c \
				ft_stack_swap.c \
				push_swap_utils.c

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
