#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	cout << "Bureaucrat default constructor called" << endl;
}

Bureaucrat::Bureaucrat(const string& name, int grade) : name(name)
{
	// cout << "Bureaucrat constructor called" << endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else
		this->grade = grade;
	// cout << this << "is created!" << endl;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat default destrcutor" << endl;
}

int Bureaucrat::operator * (const Bureaucrat& bureaucrat)
{
	// cout << "Bureaucrat operator = called" << endl;
	return (bureaucrat.grade);
}

// void Bureaucrat::operator << (const Bureaucrat& bureaucrat)
// {
// 	cout << bureaucrat.name << ", grade " << bureaucrat.grade << endl; 
// }

ostream& operator << (ostream& out, Bureaucrat& bureaucrat)
{
	out << endl;
	out << bureaucrat.getName() << ", grade: " << bureaucrat.getGrade() << endl;
	out << endl;
	return (out);
}

void Bureaucrat::incrementGrade()
{
	try
	{
		this->grade--;
		if (this->grade < 1)
			throw GradeTooHighException();
		else if (this->grade > 150)
			throw GradeTooLowException();
	}
	catch (GradeTooHighException &e)
	{
		cout << e.what() << endl;
	}
	catch (GradeTooLowException &e)
	{
		cout << e.what() << endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		this->grade++;
		if (this->grade < 1)
			throw GradeTooLowException();
		else if (this->grade > 150)
			throw GradeTooHighException();
	}
	catch (GradeTooHighException &e)
	{
		cout << e.what() << endl;
	}
	catch (GradeTooLowException &e)
	{
		cout << e.what() << endl;
	}
}

string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::signForm(AForm& form)
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
