#include "BitcoinExchange.hpp"
int main(int argc, char **argv){
	try
	{
		(void)argv;
		if(argc != 2)
			throw std::runtime_error("Wrong number of arguments. Just give me inputfile");
		std::map<std::string, float> database = storedata();
		handleinput(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}