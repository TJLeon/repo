/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:14:41 by folim             #+#    #+#             */
/*   Updated: 2024/07/15 21:14:42 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM_H__
    #define __FORM_H__

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        size_t  const          _SignGrade;
        size_t  const          _ExeGrade;
    public:
        AForm(std::string name, int SignGrade, int ExeGrade);
        virtual ~AForm();
        AForm(const AForm &src);
        AForm &operator=(const AForm &src);
        const std::string   getName() const;
        bool                getSign() const;
        void                setSign(bool i);
        size_t              getSignGrade() const;
        size_t              getExeGrade() const;
        void                beSigned(Bureaucrat &bureaucrat);
        virtual void        execute(Bureaucrat const & executor) const = 0;
        
        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };

        class OpenFileErrorException : public std::exception{
            public:
                const char *what() const throw();
        };

        class FormNotSignedException : public std::exception{
            public:
                const char *what() const throw();
        };

};

std::ostream    &operator<<(std::ostream &o, AForm &obj);

#endif
