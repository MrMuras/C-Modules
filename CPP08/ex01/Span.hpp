#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>

class Span
{
	public:
		// Constructors
		Span();
		Span(const Span &copy);
		Span(unsigned int N);
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=(const Span &assign);
		
		// Getters / Setters
		unsigned int getN() const;
		void setN(unsigned int N);
		
		// Exceptions
		class empty : public std::exception {
			virtual const char* what() const throw();
		};
		
		class full : public std::exception {
			virtual const char* what() const throw();
		};

		void addNumber(int);
		int shortestSpan();
		int longestSpan();
		void addRange(int *begin, int *end);
		
	private:
		unsigned int _N;
		std::vector<int> _numbers;
};

#endif