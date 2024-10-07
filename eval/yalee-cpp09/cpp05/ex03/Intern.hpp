#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
private:
    string name;
public:
    Intern();
    Intern(string const & name);
    ~Intern();
    AForm* makeForm(const string & param, const string & target);
    void setName(string const & name);
    string getName() const;
};

#endif
