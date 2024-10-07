#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"
#include "TargetDirectoryObj.hpp"
#include <stdio.h>

using std::string;

const string TREE =     
        "       _-_\n"
        "    /~~   ~~\\\n"
        " /~~         ~~\\\n"
        "{               }\n"
        " \\  _-     -_  /\n"
        "   ~  \\\\ //  ~\n"
        "_- -   | | _- _\n"
        "  _ -  | |   -_\n"
        "      // \\\\\n";

class AForm;
class TargetDirectoryObj;

class ShrubberyCreationForm : public AForm
{
private:
    TargetDirectoryObj target;
public:
    ShrubberyCreationForm(const string& target);
    ~ShrubberyCreationForm();
    string getTarget();
    void execute(Bureaucrat const & executor);
};

#endif