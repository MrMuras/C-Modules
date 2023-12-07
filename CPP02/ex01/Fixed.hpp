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

		// Public Methods
		float toFloat(void)const;
		int toInt(void)const;

		// Getters / Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw);

	private:
		int _fp_value;
		static const int _fract_bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);
#endif