#include "Span.hpp"

// Constructors
Span::Span():_N(0){
	std::cout << "\e[0;33mDefault Constructor called of Span\e[0m" << std::endl;
}

Span::Span(const Span &copy): _N(copy.getN()){
	std::cout << "\e[0;33mCopy Constructor called of Span\e[0m" << std::endl;
}

Span::Span(unsigned int N): _N(N){
	std::cout << "\e[0;33mFields Constructor called of Span\e[0m" << std::endl;
}


// Destructor
Span::~Span(){
	std::cout << "\e[0;31mDestructor called of Span\e[0m" << std::endl;
}


// Operators
Span & Span::operator=(const Span &assign)
{
	if (this != &assign){
		_N = assign.getN();
		_numbers = assign._numbers;
	}
	return *this;
}


// Getters / Setters
unsigned int Span::getN() const
{
	return _N;
}
void Span::setN(unsigned int N)
{
	_N = N;
}
void Span::addNumber(int number) {
	if (_numbers.size() >= _N) {
		throw(full());
	}
	_numbers.push_back(number);
}
int Span::shortestSpan(){
	if (_numbers.size() <= 1)
		throw empty();
	std::sort(_numbers.begin(), _numbers.end());
	int shortest =  _numbers[1] - _numbers[0];
	for (size_t i = 2; i < _numbers.size(); ++i){
		int span = _numbers[i] - _numbers[i - 1];
		if (span < shortest)
			shortest = span;
	}
	return shortest;
}

int Span::longestSpan(){
	if (_numbers.size() <= 1)
		throw empty();
	std::sort(_numbers.begin(), _numbers.end());
	return (std::abs(_numbers.front() - _numbers.back()));
}

void Span::addRange(int *begin, int *end){
	if(_numbers.size() + std::distance(begin, end) > _N) {
		throw(full());
	}
	_numbers.insert(_numbers.end(), begin, end);
}
// Exceptions

const char * Span::empty::what() const throw()
{
	return "Span is empty";
}

const char * Span::full::what() const throw()
{
	return "Span is full";
}
