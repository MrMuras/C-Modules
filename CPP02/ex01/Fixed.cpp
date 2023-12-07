#include "Fixed.hpp"

// Constructors
Fixed::Fixed():_fp_value(0){
	std::cout << "\e[0;33mDefault Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const int value){
	_fp_value = value << _fract_bits;
	std::cout << "\e[0;33mInt Constructor called of Fixed\e[0m" << std::endl;
}

Fixed::Fixed(const float value){
	_fp_value = static_cast<int>(roundf(value * (1 << _fract_bits)));
	std::cout << "\e[0;33mFloat Constructor called of Fixed\e[0m" << std::endl;
}


Fixed::Fixed(const Fixed &copy): _fp_value(copy.getRawBits()){
	std::cout << "\e[0;33mCopy Constructor called of Fixed\e[0m" << std::endl;
}

// Destructor
Fixed::~Fixed(){
	std::cout << "\e[0;31mDestructor called of Fixed\e[0m" << std::endl;
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign){
	std::cout << "\e[0;34mCopy assignment operator called \e[0m" << std::endl;
	_fp_value = assign.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

// Getters / Setters
int Fixed::getRawBits() const{
	std::cout << "\e[0;35mgetRawBits Funcion called\e[0m" << std::endl;
	return _fp_value;
}

void Fixed::setRawBits(int const raw){
	_fp_value = raw;
}

// Functions

int Fixed::toInt(void) const{
	return _fp_value >> _fract_bits;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fp_value) / (1 << _fract_bits);
}
