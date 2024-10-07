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

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target):
    AForm("Presidential Pardon Form", 25, 5), _target(target){
        std::cout << "Constructor [PresidentialPardonForm, " << this->_target << "]\n";
        std::cout << *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "Destructor [RobotomyRequestForm, " << getTarget() << "]\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src):
    AForm(src.getName() + "_copy", src.getSignGrade(), src.getExeGrade()){
        this->setSign(src.getSign());
        std::cout << "Copy Constructor [PresidentialPardonForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
        std::cout << *this;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &src){
    this->setSign(src.getSign());
    std::cout << "Copy Assignment Operator [PresidentialPardonForm, " << this->_target << ", copied from "<< src.getTarget() << "]\n";
    std::cout << *this;
    return *this;
}

std::string PresidentialPardonForm::getTarget() const{
    return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    std::cout << "Bureaucrat " << executor.getName() << " is executing Presidential Pardon Form for " << this->getTarget() <<"..\n";
    if (this->getExeGrade() < executor.getGrade())
        throw(AForm::GradeTooLowException());
    else if (!this->getSign())
        throw(AForm::FormNotSignedException());
    std::cout << this->getTarget() << ", you have been pardoned by Zaphod Beeblebrox!\n";
}