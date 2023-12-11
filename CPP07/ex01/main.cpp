#include "iter.hpp"

template<typename T>
void printElement(T x){
	std::cout << x << " ";
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "Printing Array elements: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	std::cout << "Printing Array elements: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;

	return 0;
}