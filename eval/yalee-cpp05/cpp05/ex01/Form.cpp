#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{

    cout << "default form constructor" << endl;
}

string Form::getName()
{
    return (this->name);
}

bool Form::getIsSigned()
{
    return (this->isSigned);
}

int Form::getGradeToSign()
{
    return (this->gradeToSign);
}

int Form::getGradeToExecute()
{
    return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat& bureaucrat)
{

    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw Form::Grade2High;
    else
        this->isSigned = true;
}

Form::Form(const string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    cout << "form constructor called" << endl;

    if (gradeToSign < 1)
        throw Form::Grade2Low;
    else if (gradeToSign > 150)
        throw Form::Grade2High;
}

Form::~Form()
{

}

ostream& operator << (ostream& out, Form& form)
{
    out << "name: " << form.getName();
    if (form.getIsSigned() == 1)
        out << "\nis signed?: yes";
    else
        out << "\nis signed?: no";
    out << "\ngrade to sign: " << form.getGradeToSign() << endl;
    out << "\ngrade to execute: " << form.getGradeToExecute() << endl;
    return (out);
}
