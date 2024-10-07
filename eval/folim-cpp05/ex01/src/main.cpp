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
#include "../include/Form.hpp"
#include <iostream>

void test_for_ex00(){
    std::cout << "\n >>> Running Test for ex_00! <<<\n";
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
    std::cout << "\n";
}

void    test_for_ex01(){
    std::cout << "\n>>> Running Test for ex_01! <<<\n";
    {
        std::cout << "Test Constructor\n";
        try{
            Form attendence("Attendence", 68, -1);
        } catch (Form::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        } catch (Form::GradeTooHighException &e){
            std::cerr << e.what() << "\n";
        }
        try{
            Form donation("Donation", 419, 68);
        } catch (Form::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        } catch (Form::GradeTooHighException &e){
            std::cerr << e.what() << "\n";
        }
    }

    {
        std::cout << "\nTest Copy Constructor\n";
        Form test("Test", 75, 75);
        Form test_copy(test);

        std::cout << "\nTest Copy Assignment Operator\n";
        Bureaucrat candidate("Candidate", 49);
        test.beSigned(candidate);
        Form pre_test("Pre_Test", 50, 50);
        pre_test = test;
    }

    {
        std::cout << "\nTest Form beSigned function\n";
        Bureaucrat adam("Adam", 25);
        Bureaucrat eve("Eve", 26);
        Form       rank25("Rank25", 25, 25);
        try{
            rank25.beSigned(eve);
        } catch (Form::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        rank25.beSigned(adam);
        rank25.beSigned(eve);
    }

    {
        std::cout << "\nTest Bureaucrat signForm function\n";
        Bureaucrat adam("Adam", 25);
        Bureaucrat eve("Eve", 26);
        Form       rank25("Rank25", 25, 25);
        try{
            eve.signForm(rank25);
        } catch (Form::GradeTooLowException &e){
            std::cerr << e.what() << "\n";
        }
        adam.signForm(rank25);
        eve.signForm(rank25);
    }
    std::cout << "\n";
}


int main(){

    // test_for_ex00();
    test_for_ex01();

    return 0;
}
