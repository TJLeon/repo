NAME = pipex
SRC_DIR = src/
SRC_FILES = $(SRC_DIR)main.c $(SRC_DIR)pipex_util.c
OBJS = $(SRC_FILES:.c=.o)
HEADER = header/
CFLAGS = -Wall -Wextra -Werror -I $(HEADER)
LIBFT = libft/libft.a
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
