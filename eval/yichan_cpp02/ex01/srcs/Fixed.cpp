/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 18:11:21 by yichan            #+#    #+#             */
/*   Updated: 2023/09/08 15:56:16 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():m_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->m_value = num << m_exponential;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->m_value = roundf(num * (1 << m_exponential));

}

// copy class using = operator
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
    std::cout << "Destructor called" << std::endl;
}

// no float in class // show full in cout
std::ostream&	operator << (std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	// out << other;
    // (void)other;
	return out;
}


int     Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return m_value;
}

void	Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl;
    m_value = raw;
}


// float	Fixed::toFloat(void) const
// {
// 	return static_cast<float> ((m_value) / pow(2,m_exponential));
// }

float	Fixed::toFloat( void ) const
{
	// return static_cast<float> ((m_value) / pow(2,m_exponential)); // m_value >> 8 (<<>> not working in float somehow)
	// return static_cast<float>((m_value) / pow(2,m_exponential)); // m_value >> 8 (<<>> not working in float somehow)
	return ( (float)this->m_value / (1 << m_exponential) );
}

int	Fixed::toInt(void) const
{
	return m_value >> m_exponential;;
}
