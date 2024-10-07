/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:13:12 by folim             #+#    #+#             */
/*   Updated: 2024/07/12 18:13:13 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"


int main(){

    {
        std::cout << "\nTest Shubbery Form\n";
        Bureaucrat alex("Alex", 146);
        Bureaucrat shawn("Shawn", 138);
        Bureaucrat john("John", 145);
        Bureaucrat leon("Leon", 137);
        AForm *trees = new ShrubberyCreationForm("Home");

        try{
            trees->beSigned(alex);
        } catch (AForm::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            trees->execute(shawn);
        } catch (AForm::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            trees->execute(leon);
        } catch (AForm::FormNotSignedException &e){
            std::cerr << e.what() << "\n";
        }

        trees->beSigned(john);
        trees->execute(leon);

        delete trees;
    }

    {
        std::cout << "\nTest Robotomy Request Form\n";
        Bureaucrat alex("Alex", 73);
        Bureaucrat shawn("Shawn", 46);
        Bureaucrat john("John", 72);
        Bureaucrat leon("Leon", 45);
        AForm *p1 = new RobotomyRequestForm("Patient 1");
        AForm *p2 = new RobotomyRequestForm("Patient 2");
        AForm *p3 = new RobotomyRequestForm("Patient 3");
        AForm *p4 = new RobotomyRequestForm("Patient 4");

        try{
            p1->beSigned(alex);
        } catch (AForm::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            p1->execute(shawn);
        } catch (AForm::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            p1->execute(leon);
        } catch (AForm::FormNotSignedException &e){
            std::cerr << e.what() << "\n";
        }

        p1->beSigned(john);
        p1->execute(leon);

        john.signForm(*p2);
        john.signForm(*p3);
        john.signForm(*p4);
        leon.executeForm(*p2);
        leon.executeForm(*p3);
        leon.executeForm(*p4);

        delete p1;
        delete p2;
        delete p3;
        delete p4;
    }

    {
        std::cout << "\nTest Presidential Pardon Form\n";
        Bureaucrat  judge("Jury", 2);
        Bureaucrat  lawyer("Lawyer", 24);
        AForm       *pardonForm = new PresidentialPardonForm("Leon");

        lawyer.signForm(*pardonForm);
        try{
            lawyer.executeForm(*pardonForm);
        } catch (AForm::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }

        judge.executeForm(*pardonForm);

        delete pardonForm;
    }

    return 0;
}
