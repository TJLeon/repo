/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:01 by folim             #+#    #+#             */
/*   Updated: 2024/07/15 21:15:03 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"

Form::Form(std::string name, int SignGrade, int ExeGrade):
    _name(name), _SignGrade(SignGrade), _ExeGrade(ExeGrade) {
    this->_isSigned = false;
    std::cout << "Constructor [Form, " << this->_name << "]\n";
    std::cout << *this;
    if (SignGrade < 1 || ExeGrade < 1)
        throw Form::GradeTooHighException();
    if (SignGrade > 150 || ExeGrade > 150)
        throw Form::GradeTooLowException();
}

Form::~Form(){
    std::cout << "Destructor [Form, " << this->_name << "]\n";
}

Form::Form(const Form &src):
    _name(src.getName() + "_copy"), _SignGrade(src.getSignGrade()), _ExeGrade(src.getExeGrade()) {
    this->_isSigned = src.getSign();
    std::cout << "Copy Constructor [Form, " << this->_name << ", copied from "<< src.getName() << "]\n";
    std::cout << *this;
}

Form & Form::operator=(const Form &src){
    if (this->_isSigned != src.getSign())
        this->_isSigned = src.getSign();
    std::cout << "Copy Assignment Operator [Form, " << this->_name << ", copied from "<< src.getName() << "]\n";
    std::cout << *this;
    // std::cout << "Grade required to sign: " << this->_SignGrade << "\n";
    // std::cout << "Grade required to execute: " << this->_ExeGrade << "\n";
    return *this;
}

const std::string   Form::getName() const{
    return this->_name;
}

bool    Form::getSign() const{
    return this->_isSigned;
}

void    Form::setSign(){
    this->_isSigned = true;
}

size_t  Form::getSignGrade() const{
    return this->_SignGrade;
}

size_t  Form::getExeGrade() const{
    return this->_ExeGrade;
}

void    Form::beSigned(Bureaucrat &bureaucrat) {
    std::cout << "Form " << this->getName() << " is being reviewed by " << bureaucrat.getName() << "..\n";
    if (this->_isSigned)
        std::cout << "The form is already signed by other!\n";
    else{
        if (this->_SignGrade >= bureaucrat.getGrade()){
            this->_isSigned = true;
            std::cout << "The form " << this->getName() << " is signed by " << bureaucrat.getName() << "!\n";
        }
        else{
            throw (Form::GradeTooLowException());
        }
    }
}

const char* Form::GradeTooHighException::what() const throw(){
    return "--- Grade too high! ---";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "--- Grade too low! ---";
}

std::ostream    &operator<<(std::ostream &o, Form &obj){
    std::string status = "Not signed";
    if (obj.getSign())
        status = "Signed";
    o << "Form: " << obj.getName() << ", Status: " << status << ".\n"
        << "Grade required to sign: " << obj.getSignGrade() << ".\n"
        << "Grade required to execute: " << obj.getExeGrade() << ".\n";
    return o;
}