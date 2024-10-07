/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 23:55:28 by yichan            #+#    #+#             */
/*   Updated: 2024/04/06 20:59:35 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::m_exponential(8);

Fixed::Fixed():m_value(0)
{
    // std::cout << "Default constructor called" << std::endl;
};

Fixed::Fixed(const int num)
{
	// std::cout << "Int constructor called" << std::endl;
	this->m_value = num << m_exponential;
}

Fixed::Fixed(const float num)
{
	// std::cout << "Float constructor called" << std::endl;
	// this->m_value = floorf((num * (1 << m_exponential)) + 0.5);
	this->m_value = roundf(num * (1 << m_exponential));

}

// copy class using = operator
Fixed::Fixed(const Fixed &other)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed   &Fixed::operator = (const Fixed &other)
{
	if (this == &other) {
        return *this; // Return self if assigned to itself
    }
	m_value = other.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

// no float in class // show full in cout
std::ostream&	operator << (std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
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


float	Fixed::toFloat( void ) const
{
	// return static_cast<float> ((m_value) / pow(2,m_exponential)); // m_value >> 8 (<<>> not working in float somehow)
	return static_cast<float> ((m_value) / pow(2,m_exponential)); // m_value >> 8 (<<>> not working in float somehow)
}

int	Fixed::toInt( void ) const
{
	return m_value >> m_exponential;;
}




Fixed	&Fixed::max (Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

Fixed	&Fixed::min (Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::max (const Fixed &a, const Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::min (const Fixed &a, const Fixed &b)
{
	return ((a < b) ? a : b);
}

bool	Fixed::operator > (const Fixed &other) const
{
	return ( this->m_value > other.m_value);
}

bool	Fixed::operator < (const Fixed &other) const
{
	return ( this->m_value < other.m_value);
}

bool	Fixed::operator >= (const Fixed &other) const
{
	return ( this->m_value >= other.m_value);
}

bool	Fixed::operator <= (const Fixed &other) const
{
	return ( this->m_value <= other.m_value);
}
bool	Fixed::operator == (const Fixed &other) const
{
	return ( this->m_value == other.m_value);
}
bool	Fixed::operator != (const Fixed &other) const
{
	return ( this->m_value != other.m_value);
}

Fixed	&Fixed::operator ++ (void)
{
	++m_value;
	return (*this);
}

Fixed	&Fixed::operator -- (void)
{
	--m_value;
	return (*this);
}

Fixed	Fixed::operator ++	(int)				//post- marker int dummy
{
	Fixed tmp(*this);
	
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator --	(int)				//post- marker int dummy
{
	Fixed tmp(*this);
	
	--(*this);
	return (tmp);
}


// Fixed operato + (const Fixed& obj1, const Fixed& obj2) {
//     int sum = obj1.value + obj2.value;
//     return Fixed(sum);
// }

Fixed Fixed::operator + (const Fixed& other) const {
	// int sum = m_value + other.m_value;
	// return Fixed(m_value + other.m_value);
	Fixed	tmp;
	tmp.setRawBits((this->getRawBits() + other.getRawBits()));
	return tmp;
}

Fixed Fixed::operator - (const Fixed& other) const {
	// int minus = m_value - other.m_value;
	// return Fixed(m_value - other.m_value);
	Fixed	tmp;
	tmp.setRawBits((this->getRawBits() - other.getRawBits()));
	return tmp;
}

Fixed Fixed::operator * (const Fixed &f) const
{
	Fixed res(this->toFloat() * f.toFloat());
	return res;
}

Fixed Fixed::operator / (const Fixed &f) const
{
	Fixed res(this->toFloat() / f.toFloat());
	return res;
}

// Using (float)this->_raw >> _fractionalBits would not achieve the same result as (float)this->_raw / (1 << _fractionalBits). Let's break down why:

// (float)this->_raw >> _fractionalBits:

// This expression performs a right-shift operation on the integer value this->_raw. Right-shifting by _fractionalBits effectively divides the integer value by 2 raised to the power of _fractionalBits, but it's not equivalent to dividing by (1 << _fractionalBits).
// While this operation will move the binary point to the right _fractionalBits positions, the result won't be accurate for fractional parts less than 0.5, as the right-shift operation rounds down.
// (float)this->_raw / (1 << _fractionalBits):

// This expression first divides the integer value this->_raw by the scaling factor (1 << _fractionalBits). This is equivalent to right-shifting the value by _fractionalBits bits, but it handles fractional parts more accurately.
// Then, the result is explicitly converted to a floating-point value. This conversion ensures that you get an accurate floating-point representation with fractional parts less than 0.5.