#include "BitcoinExchange.hpp"

std::map<std::string, float> storedata(){
	std::map<std::string, float> database;
	std::ifstream datacsv("data.csv");

	if(!datacsv.is_open())
		throw std::runtime_error("Failed to open a data!");
	if (datacsv.peek() == EOF)
		throw std::runtime_error("Empty File!");
	std::string line;
	getline(datacsv, line); // removes first line from database.
	while(getline(datacsv, line)){
		std::istringstream iss(line); // store line as string to let me use string operations
		std::string date, strvalue;
		std::getline(iss, date, ',');
		std::getline(iss, strvalue, ',');
		database[date] = std::stof(strvalue); // key(date):value(value as float);
	}
	datacsv.close();
	return database;
}

void handleinput(std::string file){
	std::ifstream inputfile(file.c_str());

	if(!inputfile.is_open())
		throw std::runtime_error("Failed to open inputfile!");
	if(inputfile.peek() == EOF)
		throw std::runtime_error("Empty input!");

	

}

void	checkline(std::string line)
{
	if(line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		
}