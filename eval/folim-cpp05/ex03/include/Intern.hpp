/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 18:28:04 by folim             #+#    #+#             */
/*   Updated: 2024/07/20 18:28:08 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __INTERN_H__
    #define __INTERN_H__

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &src);
        Intern &operator=(const Intern &src);
        AForm* makeForm(std::string formName, std::string target);
};

#endif
