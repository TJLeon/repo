#include "Intern.hpp"

Intern::Intern(const string & name): name(name)
{

}

Intern::Intern()
{

}

Intern::~Intern()
{

}

static AForm *makeRobot(const string & target)
{
    return (new RobotomyRequestForm(target));
}

static AForm *makeShrub(const string & target)
{
    ShrubberyCreationForm form(target);
    return (new ShrubberyCreationForm(target));

}

static AForm *makePresident(const string & target)
{
    PresidentialPardonForm form(target);
    return (new PresidentialPardonForm(target));
}

AForm* Intern::makeForm(const string & param, const string & target)
{
    AForm* (*func_ptr[]) (const string & target) = {makePresident, makeRobot, makeShrub};
    string myForms[] = {"PresidentialPardonForm", "ShrubberyCreationForm", "RobotomyRequestForm"};
    for (int i = 0; i < 3; i++)
    {
        if (param == myForms[i])
            return (func_ptr[i](target));
        cout << i;
    }
    return NULL;
}


void Intern::setName(string const & name)
{
    this->name = name;
}

string Intern::getName() const
{
    return (name);
}