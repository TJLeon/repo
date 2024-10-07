#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

using namespace std;

class Fixed
{
private:
	int	num;
	static const int fracbits = 8;
public:
	Fixed(void);
	Fixed(const int);
	Fixed(const float);
	Fixed(const Fixed &F);
	Fixed &operator = (const Fixed &F);
	Fixed operator + (const Fixed &F);
	Fixed operator - (const Fixed &F);
	Fixed operator * (const Fixed &F);
	Fixed operator / (const Fixed &F);
	bool operator < (const Fixed &F) const;
	bool operator > (const Fixed &F) const;
	bool operator <= (const Fixed &F) const;
	bool operator >= (const Fixed &F) const;
	bool operator == (const Fixed &F) const;
	bool operator != (const Fixed &F) const;
	Fixed operator ++(int);
	Fixed operator ++ ();

	Fixed operator --(int);
	Fixed operator -- ();


	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
	static Fixed min(Fixed &f1, Fixed &f2);
	static Fixed min(const Fixed &f1, const Fixed &f2);
	static Fixed max(Fixed &f1, Fixed &f2);
	static Fixed max(const Fixed &f1, const Fixed &f2);
};

ostream &operator << (ostream &os, const Fixed &F);

#endif