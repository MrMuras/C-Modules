#include <iostream>
#include "easyfind.hpp"
#include <vector>

int main(int, char**)
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_back(4);
	numbers.push_back(5);
	std::vector<int>::iterator it;
	try{
		it = easyfind(numbers, 10);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	try{
		it = easyfind(numbers, 3);
	}
	catch (const std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	if (it != numbers.end())
		std::cout << "Found!" << std::endl;
}