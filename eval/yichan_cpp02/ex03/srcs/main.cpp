#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	{
		const Point a(0,0);
		const Point b(10.0f,0);
		const Point c(0,10.0f);
		const Point point(2,2);
		std::cout << "Inside triangle: " << (bsp(a, b, c, point) ? "True" : "False") << std::endl;
	}
	{
		const Point a(0,0);
		const Point b(10,0);
		const Point c(0,10);
		const Point point(10,10);
		std::cout << "Outside triangle: " << (bsp(a, b, c, point) ? "True" : "False") << std::endl;
	}
	{
		const Point a(0,0);
		const Point b(10,0);
		const Point c(0,10);
		const Point point(5,5);
		std::cout << "On edge: " << (bsp(a, b, c, point) ? "True" : "False") << std::endl;
	}
	{
		const Point a(0,0);
		const Point b(10,0);
		const Point c(0,10);
		const Point point(0,0);
		std::cout << "On vertex: " << (bsp(a, b, c, point) ? "True" : "False") << std::endl;
	}
}

