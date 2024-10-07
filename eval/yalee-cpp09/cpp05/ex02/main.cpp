#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	PresidentialPardonForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	// RobotomyRequestForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	// ShrubberyCreationForm form("/Users/leeyang/Documents/CPP/cpp05/ex01/");
	cout << "------------------------------" << endl;
	{
		cout << "sign grade test - invalid" << endl;
		cout << form;
		Bureaucrat bureaucrat("william", form.getGradeToSign() + 1);
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << "------------------------------" << endl;
		cout << "valid execute test - no sign" << endl;
		{
			Bureaucrat executor("laian", form.getGradeToExecute() - 1);
			cout << form;
			cout << executor;
			form.execute(executor);
		}
		cout << "------------------------------" << endl;
		cout << "invalid execute test - no sign" << endl;
		{
			Bureaucrat executor("cyuxian", form.getGradeToExecute() + 1);
			cout << form;
			cout << executor;
			form.execute(executor);
		}
	}
	cout << "------------------------------" << endl;
	cout << "------------------------------" << endl;
	{
		cout << "sign grade test - valid" << endl;
		cout << form;
		Bureaucrat bureaucrat("william", form.getGradeToSign() - 1);
		cout << bureaucrat;
		bureaucrat.signForm(form);
		cout << "------------------------------" << endl;
		cout << "valid execute test - sign" << endl;
		{
			Bureaucrat executor("laian", form.getGradeToExecute() - 1);
			cout << form;
			cout << executor;
			form.execute(executor);
		}
		cout << "------------------------------" << endl;
		cout << "invalid execute test - sign" << endl;
		{
			Bureaucrat executor("cyuxian", form.getGradeToExecute() + 1);
			cout << form;
			cout << executor;
			form.execute(executor);
		}
	}
	cout << "------------------------------" << endl;
}