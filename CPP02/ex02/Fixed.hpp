#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const int value);
		Fixed(const float value);
		Fixed(const Fixed &copy);
		
		// Destructor
		~Fixed();
		
		// Operators
		Fixed & operator=(const Fixed &assign);
		Fixed operator+(const Fixed &) const;
		Fixed operator-(const Fixed &) const;
		Fixed operator*(const Fixed &) const;
		Fixed operator/(const Fixed &) const;

		// Comparison operators
		bool	operator==(const Fixed &) const;
		bool	operator>(const Fixed &) const;
		bool	operator<(const Fixed &) const;
		bool	operator>=(const Fixed &) const;
		bool	operator<=(const Fixed &) const;
		bool	operator!=(const Fixed &) const;

		// in/decrement operators
		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		// Public Methods
		float toFloat(void)const;
		int toInt(void)const;

		// Getters / Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw);

		// Min
		static Fixed	&min(Fixed &, Fixed &);
		static Fixed	const &min(Fixed const &, Fixed const &);

		// Max
		static Fixed	&max(Fixed &, Fixed &);
		static Fixed	const &max(Fixed const &, Fixed const &);
	private:
		int _fp_value;
		static const int _fract_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);
#endif