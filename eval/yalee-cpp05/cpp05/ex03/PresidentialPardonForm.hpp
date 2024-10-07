#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include "TargetDirectoryObj.hpp"

class PresidentialPardonForm : public AForm
{
private:
    TargetDirectoryObj target;
public:
    PresidentialPardonForm(const string & target);
    ~PresidentialPardonForm();
    string getTarget() const;
    void execute(Bureaucrat const & executor);
};

#endif