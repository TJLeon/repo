#include "AForm.hpp"

string AForm::getName() const
{
    return (this->name);
}

AForm::AForm(const string& name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    cout << "created a" << this->getName() << endl;

    if (gradeToSign < 1)
        throw GradeTooLowException();
    else if (gradeToSign > 150)
        throw GradeTooHighException();
}

AForm::AForm(int gradeToSign, int gradeToExecute) : gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    cout << "AForm constructor for grades only called\n";
}

bool AForm::getIsSigned() const
{
    return (this->isSigned);
}

int AForm::getGradeToSign() const
{
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{

    if (bureaucrat.getGrade() > this->getGradeToSign())
        throw GradeTooHighException();
    else
        this->isSigned = true;
}

AForm::~AForm()
{

}

void AForm::execute(Bureaucrat const & bureaucrat)
{
    cout << bureaucrat.getName() << endl;
}

ostream& operator << (ostream& out, AForm& form)
{
    out << endl;
    out << "name: " << form.getName();
    if (form.getIsSigned() == 1)
        out << "\nis signed?: yes";
    else
        out << "\nis signed?: no";
    out << "\ngrade to sign: " << form.getGradeToSign();
    out << "\ngrade to execute: " << form.getGradeToExecute();
    out << "\n" << endl;
    return (out);
}
