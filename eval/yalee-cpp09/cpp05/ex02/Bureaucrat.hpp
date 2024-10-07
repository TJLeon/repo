#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "AForm.hpp"
#include "GradeException.hpp"
#include <exception>

using namespace std;

class AForm;

class Bureaucrat{
private:
	const string name;
	int grade;
public:
	Bureaucrat();
	Bureaucrat(const string& name, int grade);
	~Bureaucrat();
	int operator * (const Bureaucrat& b);
	string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(AForm& form);
};

ostream& operator << (ostream& out, Bureaucrat& bureaucrat);

#endif