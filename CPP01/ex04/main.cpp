#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void replace(const std::string &filename, const std::string &s1,const std::string &s2)
{
	std::ifstream inputFile(filename);
	std::string filecontains;
	std::ofstream outputFile;
	std::ostringstream buffer;
	std::string inputFileName(filename);

	if(!inputFile.is_open()){
		std::cout << "Cant open inputFile " << std::endl;
		return ;
	}
	buffer << inputFile.rdbuf();
	filecontains = buffer.str();
	for(size_t i = 0; i < filecontains.length(); i++){
		i = filecontains.find(s1, i);
		if (i == std::string::npos) break;
		filecontains.erase(i, s1.length());
		filecontains.insert(i, s2);
	}
	inputFile.close();
	outputFile.open(inputFileName + ".replace");
	outputFile << filecontains;
	outputFile.close();
}

int main(int argc, char **argv){
	
	if (argc != 4){
		std::cout << "Feed me fouoouuur arguemnts" << std::endl;
		return (0);
	}
	replace(std::string(argv[1]), std::string(argv[2]), std::string(argv[3]));
	// testing 
	replace(std::string("test"), std::string("Wszystko"), std::string("Nic"));
	return 0;
}