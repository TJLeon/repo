COMPILER	= cc

FLAGS		= -Wall -Wextra -Werror

NAME		= minitalk

SERVER		= server

CLIENT		= client

SERVER_OBJ	= server.o

CLIENT_OBJ	= client.o

$(NAME): $(SERVER) $(CLIENT)

bonus: 
		$(COMPILER) $(FLAGS) -c $(SERVER_OBJ:.o=_bonus.c)
		$(COMPILER) $(FLAGS) -o server $(SERVER_OBJ:.o=_bonus.o)
		$(COMPILER) $(FLAGS) -c $(CLIENT_OBJ:.o=_bonus.c)
		$(COMPILER) $(FLAGS) -o client $(CLIENT_OBJ:.o=_bonus.o)

$(SERVER):
		$(COMPILER) $(FLAGS) -c $(SERVER_OBJ:.o=.c)
		$(COMPILER) $(FLAGS) -o $@ $(SERVER_OBJ)

$(CLIENT):
		$(COMPILER) $(FLAGS) -c $(CLIENT_OBJ:.o=.c)
		$(COMPILER) $(FLAGS) -o $@ $(CLIENT_OBJ)

all: $(NAME)

clean:
		rm -f $(SERVER_OBJ)
		rm -f $(CLIENT_OBJ)
		rm -f $(SERVER_OBJ:.o=_bonus.o)
		rm -f $(CLIENT_OBJ:.o=_bonus.o)

fclean: clean
		rm -f $(SERVER)
		rm -f $(CLIENT)

re: fclean all

.PHONY: all, clean, fclean, re, bonus
