# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yichan <yichan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/07 18:32:49 by yichan            #+#    #+#              #
#    Updated: 2023/08/02 17:18:52 by yichan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	a.out
INCLUDES	=	./includes
CXX			=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -g3 -std=c++98 -pedantic
SRCS_PATH	=	./srcs
OBJS_PATH	=	./objs
SRCS		=	$(wildcard $(SRCS_PATH)/*.cpp)
OBJS		=	$(patsubst $(SRCS_PATH)/%.cpp, $(OBJS_PATH)/%.o, $(SRCS))

RESET		=	\033[0m
GREEN		=	\033[38;5;46m
WHITE		=	\033[38;5;15m
GREY		=	\033[38;5;8m
ORANGE		=	\033[38;5;202m
RED			=	\033[38;5;160m

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CXX) $(CXXFLAGS) $^ -o $@
				@echo "The program name is $(RED)./$(NAME) $(RESET)"

$(OBJS_PATH)/%.o	:	$(SRCS_PATH)/%.cpp $(INCLUDES) ./Makefile
						mkdir -p $(@D)
						$(CXX) $(CXXFLAGS) -I$(INCLUDES) -c $< -o $@

clean				:
						rm -rf $(OBJS_PATH)
						
fclean				:	clean
						rm -rf $(NAME)
						
re					:	fclean all

run					:	all
						./$(NAME)

valgrind		:
					valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt $(NAME)

.PHONY				:	clean fclean re all