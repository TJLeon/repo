#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const string & target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
    cout << "Robotomy form number constructor called" << endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    cout << "Robotomy destructor" << endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)
{
    try {
    if (!this->isSigned)
        throw NotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw GradeTooLowException();
    else
    {
        srand(static_cast<unsigned int>(time(NULL)));
        int gacha = rand() % 2;
        if (gacha == 0)
        {
            cout << "reeeeeeeeeee........" << endl;
            cout << this->target.getPath() + " has been robotomized successfully!" << endl;
        }
        else
            cout << "Robotomy failed!" << endl;
    }
    } catch (exception &e){
        cout << "cannot execute because " << e.what() << endl;
    }
}