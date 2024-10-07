/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:13:12 by folim             #+#    #+#             */
/*   Updated: 2024/08/06 01:36:02 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

int main(){

    {
        std::cout << "Test Grade too high:\n";
        Bureaucrat john("John", 1);
        try{
        john.incrementGrade();
        } catch (Bureaucrat::GradeTooHighException &e){
            std::cerr << e.what() << "\n";
        }
        std::cout << john;
        std::cout << "\nTest Copy Constructor:\n";
        Bureaucrat john_copy(john);
        john_copy.decrementGrade();
        std::cout << john_copy;
    }
    {
        std::cout << "\nTest Grade too low:\n";
        Bureaucrat leon("Leon", 150);
        try{
            leon.decrementGrade();
        } catch (Bureaucrat::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        std::cout << leon;
        std::cout << "\nTest Copy Assignment Operator:\n";
        Bureaucrat joseph("Joseph", 25);
        std::cout << joseph;
        joseph = leon;
        std::cout << joseph;

    }

    {
        std::cout << "\nTest Grade Instantiation:\n";
        try{
            Bureaucrat john("John",151);
        } catch (Bureaucrat::GradeTooHighException &e){
            std::cerr << e.what() << "\n";
        } catch (Bureaucrat::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            Bureaucrat john("John",0);
        } catch (Bureaucrat::GradeTooHighException &e){
            std::cerr << e.what() << "\n";
        } catch (Bureaucrat::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
    }
    return 0;
}
