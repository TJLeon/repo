#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <ostream>

using namespace std;

class Fixed{
private:
    int integer;
    static const int fixed_int = 8;
public:
    Fixed(void);
    Fixed(const Fixed& other);
    Fixed(const int num);
    Fixed(const float num);
    float toFloat(void) const;
    int toInt(void) const;
    Fixed& operator=(const Fixed& other);
    ~Fixed();
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

std::ostream &operator << (std::ostream &os, const Fixed &F);

#endif