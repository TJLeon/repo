#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const string & target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
    cout << "presidential pardon form default destructor" << endl;
}

string PresidentialPardonForm::getTarget() const
{
    return target.getPath();
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)
{
    try {
    if (!isSigned)
        throw NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        cout << target.getPath() << " has been pardoned by Zaphod Beeblebrox!" << endl;
    }
    } catch (exception &e){
        cout << "cannot execute because " << e.what() << endl;
    }
}