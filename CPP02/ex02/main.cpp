#include <iostream>
#include <iomanip>
#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c;
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << "b: " << b << std::endl;
	c = a + b;
	std::cout << "c = a + b: " << c << std::endl;
	c = a - b;
	std::cout << "c = a - b: " << c << std::endl;
	c = a * b;
	std::cout << "c = a * b: " << c << std::endl;
	c = a / b;
	std::cout << "c = a / b:" << c << std::endl;
	std::cout << "a: " << a << " b: " << b << std::endl;
	std::cout << " a > b: " << (b > a) << std::endl;
	std::cout << " a < b: " << (b < a) << std::endl;
	std::cout << " a >= b: " << (b >= a) << std::endl;
	std::cout << " a <= b: " << (b <= a) << std::endl;
	std::cout << " a == b: " << (b == a) << std::endl;
	std::cout << " a != b: " << (b != a) << std::endl;

	return 0;
}