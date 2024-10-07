#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

#include <exception>

class GradeTooHighException: public exception
{
public:
	const char *what() const throw();
};

class GradeTooLowException: public exception
{
public:
	const char *what() const throw();
};

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
	void operator << (const Bureaucrat& b);
	int operator * (const Bureaucrat& b);
	string getName();
	int getGrade();
	void incrementGrade();
	void decrementGrade();
};

ostream& operator << (ostream& out, Bureaucrat& bureaucrat);


#endif