/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:11:21 by yichan            #+#    #+#             */
/*   Updated: 2024/04/02 00:52:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():m_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed   &Fixed::operator = (const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
//	this->m_value = other.m_value;
    if (this == &other) {
        return *this; // Return self if assigned to itself
    }
	m_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
    std::cout << "[Fixed] Destructor called" << std::endl;
}

int     Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return m_value;
}

void	Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    m_value = raw;
}

