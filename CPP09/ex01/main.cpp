#include "RPN.hpp"

int main(int argc, char ** argv) {
	try{
		if(argc != 2)
			throw std::runtime_error("Argument count != 2;");
		std::string rpnExpression = argv[1];
		checkExpression(rpnExpression);
		int result = evaluateRPN(rpnExpression);
		std::cout << "Result: " << result << std::endl;
	}
	catch(const std::exception& e){
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}