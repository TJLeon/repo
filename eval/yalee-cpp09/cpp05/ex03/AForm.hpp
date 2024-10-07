#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Bureaucrat.hpp"
#include <exception>
#include "GradeException.hpp"
#include "NotSignedException.hpp"

using namespace std;

class Bureaucrat;

class AForm
{
private:
	const string name;
	const int gradeToSign;
	const int gradeToExecute;
protected:
	bool isSigned;
public:
	virtual ~AForm() = 0;
	AForm(const string& name, int gradeToSign, int gradeToExecute);
	AForm(int gradeToSign, int gradeToExecute);
	string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	virtual void execute(Bureaucrat const & executor);
	void beSigned(Bureaucrat&  bureaucrat);
};

ostream& operator << (ostream& out, AForm& form);

#endif