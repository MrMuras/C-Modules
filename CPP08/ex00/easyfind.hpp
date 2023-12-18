#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <iterator>
# include <exception>

class Easy: public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return("Not found");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int i){
	typename T::iterator it = std::find(container.begin(), container.end(), i);
	if(it == container.end()){
		throw(Easy());
	}
	return it;
}
#endif