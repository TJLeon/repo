#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <string>
#include "TargetDirectoryObj.hpp"
#include <ctime>

using std::string;

class RobotomyRequestForm : public AForm
{
private:
    TargetDirectoryObj target;
public:
    RobotomyRequestForm(const string& target);
    ~RobotomyRequestForm();
    string getTarget() const;
    void execute(Bureaucrat const & executor);
};

#endif