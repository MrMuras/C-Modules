#include <iostream>
#include <string>

int main(){
	std::string brainz = "HI THIS IS BRAIN";
	std::string *brainzPointer = &brainz;
	std::string &brainzREF = brainz;

	std::cout << "• The memory address of the string variable:	"<< &brainz << std::endl;
	std::cout << "• The memory address held by stringPTR:		"<< brainzPointer << std::endl;
	std::cout << "• The memory address held by stringREF:		"<< &brainz << std::endl;

	std::cout << "• The value of the string variable.:		"<< brainz << std::endl;
	std::cout << "• The value pointed to by stringPTR:		"<< *brainzPointer << std::endl;
	std::cout << "• The value pointed to by stringREF:		"<< brainzREF << std::endl;

}