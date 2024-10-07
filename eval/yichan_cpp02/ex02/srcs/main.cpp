#include "Fixed.hpp"
#include <iostream>
#include <iomanip>

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    // Fixed const f(INT_MAX * (1 << 8));
    Fixed const c( 100);
    Fixed const d( 200);
    // std::cout << " f:\t" << f << std::endl;
    std::cout << " a:\t" << a << std::endl;
    std::cout << " ++a:\t" << ++a << std::endl;
    // std::cout << " a:\t" << a << std::endl;
    std::cout << " a++:\t" << a++ << std::endl;
    std::cout << " a:\t" << a << std::endl;
    std::cout << " b:\t" << b << std::endl;
    std::cout << " Fixed::max( a, b ):\t" << Fixed::max( a, b ) << std::endl;

    std::cout << "COMPARISON OPERATOR TEST" << std::endl;
    std::cout << std::boolalpha;
    std::cout << (c<=b) << std::endl;
    std::cout << (c>=b) << std::endl;

    return 0;
}

// int main(void)
// { 
//     Fixed a(12.04f);

//     std::cout << a << std::endl;
// }

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	Fixed const c(Fixed( 5.05f ) / Fixed( 2 ) );
// 	Fixed d(5.04f);
// 	Fixed e(5.05f);

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a.getRawBits() << std::endl;
//     std::cout << b << std::endl;
//     std::cout << b << std::endl;
//     std::cout << Fixed::max( a, b ) << std::endl;
//     std::cout << "\n" << std::endl;

// 	std::cout << "b is " << b << std::endl;
// 	std::cout << "b is " << b.toInt() << " as int" << std::endl;
// 	std::cout << "c is " << c << std::endl;
// 	std::cout << "c is " << c.toInt() << " as int" << std::endl;
// 	std::cout << (d == e) << std::endl;
// 	std::cout << --d << std::endl;
// 	std::cout << Fixed( 5.05f ) << std::endl;
// 	std::cout << Fixed( 2 ) << std::endl;

// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	std::cout << Fixed::min( d, e ) << std::endl;

// 	return 0;
// }
