COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

MLX_FLAGS	= -Lmlx_opengl -lmlx -framework OpenGL -framework AppKit

MLX_DIR		= mlx_opengl

NAME		= so_long

SRC_DIR		= code_folder

SRC			= copy_map.c \
				file_to_map.c \
				floodfield.c \
				ft_bzero.c \
				ft_calloc.c \
				ft_strlen.c \
				game_init.c \
				get_file.c \
				get_map.c \
				map_valid.c \
				render_map.c \
				so_long.c \
				user_input.c

OBJ			= $(SRC:.c=.o)

$(NAME): $(OBJ)
		make -C $(MLX_DIR) 2>/dev/null
		$(COMPILER) $(FLAGS) -I$(SRC_DIR) -I$(MLX_DIR) $(MLX_FLAGS) -o $(NAME) $(OBJ)

$(OBJ):
		$(COMPILER) $(FLAGS) -I$(SRC_DIR) -I$(MLX_DIR) -c $(SRC_DIR)/$(@:.o=.c)

all: $(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
		make clean -C $(MLX_DIR)

re: fclean all

.PHONY: all, clean, fclean, re
