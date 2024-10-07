#include "Fixed.hpp"
#include <cmath>

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

Fixed::Fixed(const int num)
{
    cout << "const int constructor" << endl;
    Fixed::integer = num * (1 << Fixed::fixed_int);
}

Fixed::Fixed(const float num)
{
    cout <<"const float constuctor" << endl;
    Fixed::integer = roundf(num * (1 << Fixed::fixed_int));
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(Fixed::integer) / (float)(1 << Fixed::fixed_int));
}

int Fixed::toInt(void) const
{
    return ((Fixed::integer << Fixed::fixed_int));
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

std::ostream &operator << (std::ostream &os, const Fixed &F)
{
	os << F.toFloat();
	return os;
}