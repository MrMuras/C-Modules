#include "Base.hpp"

Base::~Base(){}


class A : public Base{};
class B : public Base{};
class C : public Base{};

Base	*generate(){

	int randomValue = rand() % 3;

	switch (randomValue) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void	identify(Base *p){
	if(dynamic_cast<A*>(p))
		std::cout << "It's A!" << std::endl;
	else if(dynamic_cast<B*>(p))
		std::cout << "It's B!" << std::endl;
	else if(dynamic_cast<C*>(p))
		std::cout << "It's C!" << std::endl;
	else
		std::cout << "It's not A, B or C!" << std::endl;
}


void identify(Base& p) {
	try {
		A &a  = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It's A!" << std::endl;
	} catch (std::bad_cast&) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It's B!" << std::endl;
	} catch (std::bad_cast&) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It's C!" << std::endl;
	} catch (std::bad_cast&) {}
}