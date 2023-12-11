#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
template<typename T>
class Array
{
	public:
		Array(): _size(0)
		{
			_array = new T[_size];
			std::cout << "\e[0;33mDefault Constructor called of Array\e[0m" << std::endl;
		}

		Array(const Array<T> &copy): _size(copy.size())
		{
			_array = new T[_size];

			for(unsigned int i = 0; i < _size; ++i){
				_array[i] = copy._array[i];
			}
			std::cout << "\e[0;33mCopy Constructor called of Array\e[0m" << std::endl;
		}

		Array(unsigned int size): _size(size)
		{
			_array = new T[size];
			std::cout << "\e[0;33mFields Constructor called of Array\e[0m" << std::endl;
		}

		// Destructor
		~Array()
		{
			if(_array != nullptr)
				delete[] _array;
				_array = nullptr;
			std::cout << "\e[0;31mDestructor called of Array\e[0m" << std::endl;
		}

		// Operators
		Array<T> & operator=(const Array<T> &assign)
		{
			if (this != &assign){
				delete[] _array;
				_size = assign._size;
				_array = new T[_size];
				for(unsigned int i = 0; i < _size; ++i){
					_array[i] = assign._array[i];
				}
			}
			return *this;
		}

		T & operator[](unsigned int index) {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}
		const T & operator[](unsigned int index) const {
			if (index >= _size) {
				throw std::out_of_range("Index out of bounds");
			}
			return _array[index];
		}
		// Getters / Setters
		unsigned int size() const{
			return _size;
		}

		class outofbound : public std::exception {
			virtual const char* what() const throw();
		};

	private:
		T* _array;
		unsigned int _size;
};
	template<typename T>
	const char* Array<T>::outofbound::what() const throw() {
		return "Value out of bound of an array";
	}
#endif