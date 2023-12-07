#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
	public:
		// Constructors
		Fixed();
		Fixed(const Fixed &copy);
		
		// Destructor
		~Fixed();
		
		// Operators overload
		Fixed & operator=(const Fixed &assign);
		
		// Getters / Setters
		int getRawBits( void ) const;
		void setRawBits( int const raw);
	private:
		int _fp_value;
		static const int _fract_bits = 8;
};

#endif