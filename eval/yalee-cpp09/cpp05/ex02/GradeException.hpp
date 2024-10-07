#ifndef GRADEEXCEPTION_HPP
#define GRADEEXCEPTION_HPP

#include <string>
#include <iostream>
#include <exception>

using namespace std;

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

#endif