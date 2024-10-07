/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 21:53:39 by folim             #+#    #+#             */
/*   Updated: 2024/07/17 21:53:42 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM_H__
    #define __PRESIDENTIALPARDONFORM_H__

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
    private:
        const std::string _target;
    public:
        PresidentialPardonForm(std::string target);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &src);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
        std::string getTarget() const;
        void execute(Bureaucrat const &executor) const;
};

#endif

