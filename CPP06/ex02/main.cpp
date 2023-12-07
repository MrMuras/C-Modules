#include "Base.hpp"

int main()
{
	srand(time(nullptr));
	std::cout << "---------------Testing-----------------" << std::endl;
	Base	*b =generate();
	std::cout << "-------<Indentify with pointer>--------" << std::endl;
	identify(*b);
	std::cout << "---------<Identify with reff>----------" << std::endl;
	identify(b);
	delete(b);

}
