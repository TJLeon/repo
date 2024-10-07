/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:01 by folim             #+#    #+#             */
/*   Updated: 2024/07/15 21:15:03 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"

AForm::AForm(std::string name, int SignGrade, int ExeGrade):
    _name(name), _SignGrade(SignGrade), _ExeGrade(ExeGrade) {
    this->_isSigned = false;
    std::cout << "Constructor [AForm, " << this->_name << "]\n";
    std::cout << *this;
    if (SignGrade < 1 || ExeGrade < 1)
        throw AForm::GradeTooHighException();
    if (SignGrade > 150 || ExeGrade > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm(){
    std::cout << "Destructor [AForm, " << this->_name << "]\n";
}

AForm::AForm(const AForm &src):
    _name(src.getName() + "_copy"), _SignGrade(src.getSignGrade()), _ExeGrade(src.getExeGrade()) {
    this->_isSigned = src.getSign();
    std::cout << "Copy Constructor [AForm, " << this->_name << ", copied from "<< src.getName() << "]\n";
    std::cout << *this;
}

AForm & AForm::operator=(const AForm &src){
    if (this->_isSigned != src.getSign())
        this->_isSigned = src.getSign();
    std::cout << "Copy Assignment Operator [AForm, " << this->_name << ", copied from "<< src.getName() << "]\n";
    std::cout << *this;
    return *this;
}

const std::string   AForm::getName() const{
    return this->_name;
}

bool    AForm::getSign() const{
    return this->_isSigned;
}

void    AForm::setSign(bool i){
        this->_isSigned = i;
}

size_t  AForm::getSignGrade() const{
    return this->_SignGrade;
}

size_t  AForm::getExeGrade() const{
    return this->_ExeGrade;
}

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    std::cout << "AForm " << this->getName() << " is being reviewed by " << bureaucrat.getName() << "..\n";
    if (this->_isSigned)
        std::cout << "The AForm is already signed by other!\n";
    else{
        if (this->_SignGrade >= bureaucrat.getGrade()){
            this->_isSigned = true;
            std::cout << "The AForm " << this->getName() << " is signed by " << bureaucrat.getName() << "!\n";
        }
        else{
            throw (AForm::GradeTooLowException());
        }
    }
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "--- Grade too high! ---";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "--- Grade too low! ---";
}

const char* AForm::OpenFileErrorException::what() const throw(){
    return "-- Unable to create/open file! --";
}

const char* AForm::FormNotSignedException::what() const throw(){
    return "--- Form not signed! ---";
}

std::ostream    &operator<<(std::ostream &o, AForm &obj){
    std::string status = "Not signed";
    if (obj.getSign())
        status = "Signed";
    o << "AForm: " << obj.getName() << ", Status: " << status << ".\n"
        << "Grade required to sign: " << obj.getSignGrade() << ".\n"
        << "Grade required to execute: " << obj.getExeGrade() << ".\n";
    return o;
}