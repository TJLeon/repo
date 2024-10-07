NAME = ex03
SRC = main.cpp Bureaucrat.cpp AForm.cpp GradeException.cpp ShrubberyCreationForm.cpp NotSignedException.cpp TargetDirectoryObj.cpp RobotomyRequestForm.cpp PresidentialPardonForm.cpp Intern.cpp

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all : $(NAME)

$(NAME) : $(SRC)
	g++ -std=c++98 $(SRC) $(CFLAGS) -o $(NAME) -fsanitize=address

fclean :
	rm -f $(NAME)

re : fclean all