/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leotan <leotan@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:27:51 by folim             #+#    #+#             */
/*   Updated: 2024/08/07 22:43:00 by leotan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"

Intern::Intern(){
    std::cout << "Constructor [Intern]\n";
}

Intern::~Intern(){
    std::cout << "Destructor [Intern]\n";
}

Intern::Intern(const Intern &src){
    std::cout << "Copy Constructor [Intern]\n";
    *this = src;
}

Intern &Intern::operator=(const Intern &src){
    std::cout << "Copy Assignment Operator [Intern]\n";
    if (this != &src)
        return *this;
    return *this;
}


AForm* makeShrubberyCreation(std::string target){
    return new ShrubberyCreationForm(target);
}

AForm* makeRobotomyRequest(std::string target){
    return new RobotomyRequestForm(target);
}

AForm* makePresidentialPardon(std::string target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target){
    std::cout << "Intern: Working on form: " << formName << " with target: " << target << " ..\n";
    std::string keyword[] = {"shrubbery creation request", "robotomy request", "presidential pardon request"};
    // function pointer arrays:
    AForm* (*Forms[])(std::string target) = {&makeShrubberyCreation, &makeRobotomyRequest, &makePresidentialPardon};
    for (int i = 0; i < 3; i++){
        if (keyword[i] == formName)
            return (Forms[i](target));
    }
    std::cerr << "Form not found!\n";
    return NULL;
}
