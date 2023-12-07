#include "serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer constructor created" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy)
{
	*this = copy;
}

Serializer	&Serializer::operator=(const Serializer &object)
{
	if (this != &object){}
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}