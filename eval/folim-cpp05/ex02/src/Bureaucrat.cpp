/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:14:51 by folim             #+#    #+#             */
/*   Updated: 2024/07/12 18:14:53 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name){
    this->_grade = 75;
    setGrade(grade);
    std::cout << "Contructor [Bureaucrat, " << _name << ", " << _grade << "]\n";
}

Bureaucrat::~Bureaucrat(){
    std::cout << "Destructor [Bureaucrat, " << _name << "]\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name + "_copy"){
    this->_grade = src.getGrade();
    std::cout << "Copy Contructor [Bureaucrat, " << _name << ", " << _grade << "]\n";
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &src){
    if (this->_grade != src.getGrade())
        this->_grade = src.getGrade();
    std::cout << "Copy Assignment Operator [Bureaucrat, " << _name << ", " << _grade << "]\n";
    return *this;
}

std::string const Bureaucrat::getName() const {
    return this->_name;
}

size_t Bureaucrat::getGrade() const {
    return this->_grade;
}

void Bureaucrat::setGrade(int grade){
    // try{
        if (grade < 1)
            throw Bureaucrat::GradeTooHighException();
        else if (grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            this->_grade = grade;
}

void Bureaucrat::incrementGrade(){
    std::cout << "Incrementing grade for " << this->_name << "..\n";
    setGrade(this->_grade - 1);
}

void Bureaucrat::decrementGrade(){
    std::cout << "Decrementing grade for " << this->_name << "..\n";
    setGrade(this->_grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "--- Grade too high! ---";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "--- Grade too low! ---";
}

void    Bureaucrat::signForm(AForm &AForm){
    std::cout << "Bureaucrat " << this->getName() << " is reviewing AForm " << AForm.getName() << "..\n";
    if (AForm.getSign())
        std::cout << this->getName() << " couldn't sign AForm " << AForm.getName() << " because it had been signed by other!\n";
    else{
        if (AForm.getSignGrade() >= this->getGrade()){
            AForm.setSign(true);
            std::cout << "Bureaucrat " << this->getName() << " signed AForm " << AForm.getName() << "!\n";
        }
        else{
            throw (AForm::GradeTooLowException());
        }
    }
}

void    Bureaucrat::executeForm(AForm &AForm){
    AForm.execute(*this);
}

std::ostream    &operator<<(std::ostream &o, Bureaucrat &obj){
    o << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".\n";
    return o;
}
