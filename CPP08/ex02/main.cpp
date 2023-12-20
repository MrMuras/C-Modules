#include "MutantStack.hpp"
#include <list> 

int main()
{
	std::cout << "-----TESTING WITH MUTANTSTACK-----" << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
			{
			std::cout << *it << std::endl;
			++it;
			}
		std::stack<int> s(mstack);
	}
	std::cout << "---------TESTING WITH LIST--------" << std::endl;
	{
		std::list<int> mList; 
		mList.push_back(5);
		mList.push_back(17);
		std::cout << mList.back() << std::endl; 
		mList.pop_back();
		std::cout << mList.size() << std::endl;

		mList.push_back(3);
		mList.push_back(5);
		mList.push_back(737);

		mList.push_back(0);

		std::list<int>::iterator it = mList.begin();
		std::list<int>::iterator ite = mList.end();
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}

		std::stack<int, std::list<int> > s(mList);
	}
	std::cout << "---------Other simple test--------" << std::endl;
	{
		MutantStack<int> mutantStack;

		mutantStack.push(10);
		mutantStack.push(20);
		mutantStack.push(30);
		mutantStack.push(40);
		mutantStack.push(50);

		std::cout << "Elements in the MutantStack:" << std::endl;
		for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		mutantStack.pop();

		std::cout << "Elements after popping one:" << std::endl;
		for (MutantStack<int>::iterator it = mutantStack.begin(); it != mutantStack.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << std::endl;

		std::cout << "Top element: " << mutantStack.top() << std::endl;

		std::cout << "Is the stack empty? " << (mutantStack.empty() ? "Yes" : "No") << std::endl;

		std::cout << "Size of the stack: " << mutantStack.size() << std::endl;
	}
	return 0;
}