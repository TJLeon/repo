#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Form.hpp"
#include "GradeException.hpp"
#include <exception>

using namespace std;

class Form;

class Bureaucrat{
private:
	const string name;
	int grade;
	GradeTooHighException Grade2High;
	GradeTooLowException Grade2Low;
public:
	Bureaucrat();
	Bureaucrat(const string& name, int grade);
	~Bureaucrat();
	// void operator << (const Bureaucrat& b);
	int operator * (const Bureaucrat& b);
	string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
	void signForm(Form& form);
};

ostream& operator << (ostream& out, Bureaucrat& bureaucrat);

#endif