#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <iterator>

template<typename T>
class MutantStack : public std::stack<T>{
	public:
		// Constructors
		MutantStack() : std::stack<T>(){}
		MutantStack(const MutantStack &copy) : std::stack<T>(copy){}
		MutantStack &operator=(const MutantStack& other){
			if (this != &other)
				std::stack<T>::operator=(other);
			return (*this);
		}
		~MutantStack() {
				std::cout << "Default deconstructor called" << std::endl;
		};
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(void) {
			return this->c.begin();
		};
		iterator end(void) {
			return this->c.end();
		};
};

#endif