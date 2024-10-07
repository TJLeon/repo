#include "Fixed.hpp"

Fixed::Fixed(void)
{
    cout << "default constructor" << endl;
    Fixed::integer = 0;
}

Fixed::Fixed(const Fixed& other)
{
    cout << "kage bunshin no jutsu" << endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other)
{
    integer = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    cout << "destroyed" << endl;
}

int Fixed::getRawBits(void) const
{
    cout << "getting raw bits" << endl;
    return Fixed::integer;
}

void Fixed::setRawBits(int const raw)
{
    cout << "setting raw bits" << endl;
    Fixed::integer = raw;
}