# include <iostream>
# include "serializer.hpp"


int	main(){
	Data data;
	data.value = 42;
	data.symbol = '*';
	uintptr_t serialized = Serializer::serialize(&data);
	Data* deserialized = Serializer::deserialize(serialized);

	if(deserialized == &data)
		std::cout << "Sucess" << std::endl;
	else
		std::cout << "Failed" << std::endl;

	return 0;
}