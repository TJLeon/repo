#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const string& target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    cout << "constructor for shrubbery form" << endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    cout << "shrubbery form destructor" << endl;
}

string ShrubberyCreationForm::getTarget()
{
    return (target.getPath());
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
    try {
    if (!this->isSigned)
        throw NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        std::ofstream outfile(target.getPath() + executor.getName() + "'s Shrubbery");
        outfile << executor.getName() << "'s Shrubbery" << endl;
        outfile << TREE << endl;
        outfile << "Planted at " + target.getPath() << endl;
    }
    } catch (exception &e){
        cout << "cannot execute because " << e.what() << endl;
    }
}