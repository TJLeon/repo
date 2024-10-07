/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexlfl <folim@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 20:27:57 by alexlfl           #+#    #+#             */
/*   Updated: 2024/07/19 20:27:58 by alexlfl          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target):
    AForm("Robotomy Request Form", 72, 45), _target(target){
        std::cout << "Constructor [ShrubberyCreationForm, " << this->_target << "]\n";
        std::cout << *this;
        std::srand(time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "Destructor [RobotomyRequestForm, " << getTarget() << "]\n";

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src):
    AForm(src.getName() + "_copy", src.getSignGrade(), src.getExeGrade()){
        this->setSign(src.getSign());
        std::cout << "Copy Constructor [RobotomyRequestForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
        std::cout << *this;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &src){
    this->setSign(src.getSign());
    std::cout << "Copy Assignment Operator [RobotomyRequestForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
    std::cout << *this;
    return *this;
}

std::string RobotomyRequestForm::getTarget() const{
    return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    std::cout << "Bureaucrat " << executor.getName() << " is executing Robotomy Request Form for " << this->getTarget() <<"..\n";
    if (this->getExeGrade() < executor.getGrade())
        throw(AForm::GradeTooLowException());
    else if (!this->getSign())
        throw(AForm::FormNotSignedException());
    std::cout << "Drilling noise.... !!!\n";
    if (std::rand() % 2){
        std::cout   << "Robotomy Request Form at " << this->getTarget() << " is executed successfully by "
                    << executor.getName() << "!\n";
    }
    else{
        std::cout   << "Robotomy Request Form at " << this->getTarget() << " is fail to execute by "
                    << executor.getName() << "!\n";
    }
}