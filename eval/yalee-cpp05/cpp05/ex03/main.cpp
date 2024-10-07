#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	// PresidentialPardonForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	// RobotomyRequestForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	// ShrubberyCreationForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	Intern will("will");
	AForm *form = will.makeForm("PresidentialPardonForm", "/Users/leeyang/Documents/CPP/cpp05/ex01/");
	Bureaucrat laian("laian", 1);
	laian.signForm(*form);
	form->execute(laian);
}