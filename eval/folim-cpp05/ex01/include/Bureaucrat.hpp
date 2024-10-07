/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 18:14:29 by folim             #+#    #+#             */
/*   Updated: 2024/07/12 18:14:31 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT_H__
    #define __BUREAUCRAT_H__

#include <iostream>
#include <exception>
#include <string>
#include "Form.hpp"

class Form;

class Bureaucrat{
    private:
        const std::string   _name;
        size_t              _grade;
    public:
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &src);
        ~Bureaucrat();
        const std::string     getName() const;
        size_t          getGrade() const;
        void            setGrade(int grade);
        void            incrementGrade();
        void            decrementGrade();
        void            signForm(Form &form);

        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &o, Bureaucrat &obj);

#endif
