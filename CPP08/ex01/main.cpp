#include <iostream>
#include <cassert>
#include "Span.hpp"

int main()
{
	Span span2 = Span(5);
	for (size_t i = 0; i < 6; i++)
	{
		try
		{
			span2.addNumber(i * 3 % 5);
			std::cout << "number added!" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cerr << e.what() << std::endl<< std::endl;
		}
	}
	std::cout << "shortest distance is " << span2.shortestSpan() << std::endl;
	std::cout << "longest distance is " << span2.longestSpan() << std::endl<< std::endl;

	Span span1 = Span(20000);
	int arr[20000];
	for(int i = 0; i < 20000; i++)
		arr[i] = i;
	span1.addRange(arr, arr + 20000);
	std::cout << "shortest span is " << span1.shortestSpan() << std::endl;
	std::cout << "longest span is " << span1.longestSpan() << std::endl;

	return (0);
}