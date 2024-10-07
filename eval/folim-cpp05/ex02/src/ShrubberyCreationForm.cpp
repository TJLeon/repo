/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 23:17:33 by folim             #+#    #+#             */
/*   Updated: 2024/07/17 23:17:34 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): 
    AForm("Shubbery Creation Form", 145, 137), _target(target){
        std::cout << "Constructor [ShrubberyCreationForm, " << this->_target << "]\n";
        std::cout << *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "Destructor [ShrubberyCreationForm, " << getTarget() << "]\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src):
    AForm(src.getName() + "_copy", src.getSignGrade(), src.getExeGrade()){
        this->setSign(src.getSign());
        std::cout << "Copy Constructor [ShrubberyCreationForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
        std::cout << *this;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src){
    this->setSign(src.getSign());
    std::cout << "Copy Assignment Operator [ShrubberyCreationForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
    std::cout << *this;
    return *this;
}

std::string ShrubberyCreationForm::getTarget() const{
    return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const{
    std::cout << "Bureaucrat " << executor.getName() << " is executing Shrubbery Creation Form for " << this->getTarget() <<"..\n";
    if (this->getExeGrade() < executor.getGrade())
        throw(AForm::GradeTooLowException());
    else if (!this->getSign())
        throw(AForm::FormNotSignedException());
    std::ofstream   ofs(this->getTarget().append("_shrubbery").c_str());
    if (!ofs.is_open())
      throw (AForm::OpenFileErrorException());
    else {

        for(int i = 0; i < 3; i++){
            ofs << "                                                    \n"
                << "                                                    \n"
                << "                                              .         ;  \n"
                << "                 .              .              ;%     ;;   \n"
                << "                   ,           ,                :;%  %;   \n"
                << "                    :         ;                   :;%;'     .,\n"
                << "           ,.        %;     %;            ;        %;'    ,;\n"
                << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
                << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
                << "               ;%;      %;        ;%;        % ;%;  ,%;'\n"
                << "                `%;.     ;%;     %;'         `;%%;.%;'\n"
                << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
                << "                    `:%;.  :;bd%;          %;@%;'\n"
                << "                      `@%:.  :;%.         ;@@%;'   \n"
                << "                        `@%.  `;@%.      ;@@%;    \n"
                << "                          `@%%. `@%%    ;@@%;   \n"
                << "                            ;@%. :@%%  %@@%;  \n"
                << "                              %@bd%%%bd%%:; \n"
                << "                                #@%%%%%:;;\n"
                << "                                %@@%%%::;\n"
                << "                                %@@@%(o);  . '        \n"
                << "                                %@@@o%;:(.,'        \n"
                << "                            `.. %@@@o%::;         \n"
                << "                               `)@@@o%::;         \n"
                << "                                %@@(o)::;        \n"
                << "                               .%@@@@%::;       \n"
                << "                               ;%@@@@%::;.    \n"
                << "                              ;%@@@@%%:;;;. \n"
                << "                          ...;%@@@@@%%:;;;;,..\n"
                << "\n\n";
        }
        std::cout   << "Shrubbery Creation Form at" << this->getTarget() << " is executed successfully by "
                    << executor.getName() << "!\n";
    }
}

std::ostream    &operator<<(std::ostream &o, ShrubberyCreationForm &obj){
    std::string status = "Not signed";
    if (obj.getSign())
        status = "Signed";
    o << "ShrubberyCreationForm: " << obj.getName() << ", Status: " << status << ".\n"
        << "Grade required to sign: " << obj.getSignGrade() << ".\n"
        << "Grade required to execute: " << obj.getExeGrade() << ".\n";
    return o;
}