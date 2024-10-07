#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const string& name, int grade) : name(name)
{
	cout << "Bureaucrat constructor called" << endl;
	if (grade < 1)
		throw Bureaucrat::Grade2High;
	else if (grade > 150)
		throw Bureaucrat::Grade2Low;
	else
		this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{

}

int Bureaucrat::operator * (const Bureaucrat& bureaucrat)
{
	cout << "Bureaucrat operator = called" << endl;
	return (bureaucrat.grade);
}

// void Bureaucrat::operator << (const Bureaucrat& bureaucrat)
// {
// 	cout << bureaucrat.name << ", grade " << bureaucrat.grade << endl; 
// }

ostream& operator << (ostream& out, Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << endl;
	return (out);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		this->grade--;
		if (this->grade < 1)
			throw Bureaucrat::Grade2High;
		else if (this->grade > 150)
			throw Bureaucrat::Grade2Low;
	}
	catch (GradeTooHighException &e)
	{
		cout << "Grade too high" << endl;
	}
	catch (GradeTooLowException &e)
	{
		cout << "Grade too low" << endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		this->grade++;
		if (this->grade < 1)
			throw Bureaucrat::Grade2Low;
		else if (this->grade > 150)
			throw Bureaucrat::Grade2High;
	}
	catch (GradeTooHighException &e)
	{
		cout << "Grade too high" << endl;
	}
	catch (GradeTooLowException &e)
	{
		cout << "Grade too low" << endl;
	}
}

string Bureaucrat::getName()
{
	return (this->name);
}

int Bureaucrat::getGrade()
{
	return (this->grade);
}

void Bureaucrat::signForm(Form& form)
{
	try 
	{
		form.beSigned(*this);
	}
	catch (exception& e)
	{
		cout << this->getName() << " could not sign " << form.getName() << " becaues " << e.what() << endl;
		return ;
	}
	cout << this->getName() << " signed " << form.getName() << endl;
	return ;
}
