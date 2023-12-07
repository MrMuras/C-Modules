#include "Fixed.hpp"

// Constructors
Fixed::Fixed():_fp_value(0){
}

Fixed::Fixed(const int value){
	_fp_value = value << _fract_bits;
}

Fixed::Fixed(const float value){
	_fp_value = static_cast<int>(roundf(value * (1 << _fract_bits)));
}


Fixed::Fixed(const Fixed &copy): _fp_value(copy.getRawBits()){
}

// Destructor
Fixed::~Fixed(){
}

// Operators
Fixed & Fixed::operator=(const Fixed &assign){
	_fp_value = assign.getRawBits();
	return *this;
}

Fixed Fixed::operator+(Fixed const &b) const{
	return(toFloat() + b.toFloat());
}

Fixed Fixed::operator-(Fixed const &b) const{
	return(toFloat() - b.toFloat());
}

Fixed Fixed::operator*(Fixed const &b) const{
	return(toFloat() * b.toFloat());
}

Fixed Fixed::operator/(Fixed const &b) const{
	return(toFloat() / b.toFloat());
}

// Comparison operators
bool	Fixed::operator>(const Fixed &b) const{
	return(getRawBits() > b.getRawBits());
}

bool	Fixed::operator<(const Fixed &b) const{
	return(getRawBits() < b.getRawBits());
}

bool	Fixed::operator>=(const Fixed &b) const{
	return(_fp_value >= b.getRawBits());
}

bool	Fixed::operator<=(const Fixed &b) const{
	return(_fp_value <= b.getRawBits());
}

bool	Fixed::operator==(const Fixed &b) const{
	return(_fp_value == b.getRawBits());
}

bool	Fixed::operator!=(const Fixed &b) const{
	return(_fp_value != b.getRawBits());
}

// in/decrement operators
Fixed &Fixed::operator++(void)
{
	_fp_value++;
	return (*this);
}

// Min
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

Fixed	const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a < b)
		return a;
	return b;
}

// Max
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

Fixed	const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return a;
	return b;
}
Fixed Fixed::operator++(int){
	Fixed temp = *this;
	_fp_value++;
	return(temp);
}

Fixed &Fixed::operator--(void)
{
	_fp_value--;
	return (*this);
}

Fixed Fixed::operator--(int){
	Fixed temp = *this;
	_fp_value--;
	return(temp);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

// Getters / Setters
int Fixed::getRawBits() const{
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
