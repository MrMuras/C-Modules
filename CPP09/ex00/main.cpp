#include "BitcoinExchange.hpp"

template <typename Key, typename Value>
void printMap(const std::map<Key, Value>& myMap) {
	for (typename std::map<Key, Value>::const_iterator it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << ": " << it->second << std::endl;
	}
}

int main(int argc, char **argv){
	try
	{
		(void)argv;
		if(argc != 2)
			throw std::runtime_error("Wrong number of arguments. usage ./btc \"inputfilename\"");
		std::map<int, float> database = storedata();
		// printMap(database);
		handleinput(argv[1], database);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}