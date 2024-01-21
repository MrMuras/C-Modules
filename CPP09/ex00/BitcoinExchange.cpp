#include "BitcoinExchange.hpp"

int convertDateToInt(const std::string& dateStr) {
	std::string numericDateStr;

	for (std::size_t i = 0; i < dateStr.size(); ++i) {
		if (dateStr[i] >= '0' && dateStr[i] <= '9')
			numericDateStr += dateStr[i];
	}
	return atoi(numericDateStr.c_str());
}

std::map<int, float> storedata(){
	std::map<int, float> database;
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
		database[convertDateToInt(date)] = std::stof(strvalue); // key(date):value(value as float);
	}
	datacsv.close();
	return database;
}

void handleinput(std::string file, std::map<int, float> database){
	std::ifstream inputfile(file.c_str());
	std::string line;
	std::pair<int,float> datevalue;
	std::map<int, float>::iterator it;

	if(!inputfile.is_open())
		throw std::runtime_error("Failed to open inputfile!");
	if(inputfile.peek() == EOF)
		throw std::runtime_error("Empty input!");
	while(getline(inputfile, line)){
		if(line == "date | value")
			continue;
		try{
			datevalue = checkline(line);
			it = database.lower_bound(datevalue.first);
			 if (it != database.begin()) 
				--it;
			std::cout << line.substr(0, 10) << " ==> " << it->second * datevalue.second << std::endl;
		}
		catch(const std::exception& e){
			std::cerr << "Error: " << e.what() << " ==> " << line.substr(0, 10) << '\n';
		}
	}
}

std::pair<int, float> checkline(std::string line)
{
	if(line[4] != '-' || line[7] != '-' || line[10] != ' ' || line[11] != '|' || line[12] != ' ')
		throw std::runtime_error("Bad input format. Use \"YYYY-MM-DD | yourvalue\"");

	for(std::string::const_iterator it = line.begin(); it != line.end(); ++it)
		if(!isdigit(*it) && *it != '-'&& *it != '|'&& *it != ' '&& *it != '.')
			throw std::runtime_error("Unrecognized symbols in line!");
	std::istringstream iss(line);
	int year, month, day;
	float value;
	char dash, pipe;
	iss >> year >> dash >> month >> dash >> day >> pipe >> value;
	if (iss.fail() || !iss.eof()) 
		throw std::runtime_error("There are additional characters after value.");
	if(year < 2009 || year > 2024)
		throw std::runtime_error("Year to big or to small");
	if(day < 1 || day > 31)
		throw std::runtime_error("Invalid day");
	if(month < 1 || month > 12)
		throw std::runtime_error("Invalid month");
	if(value < 0 || value > 1000)
		throw std::runtime_error("Invalid value");
	return std::pair<int,float>(convertDateToInt(line.substr(0, 11)), value);
					// it's just for learning how stream object behave.
					// std::stringstream dateStream;
					// int date;
					// dateStream << year << month << day; concatenting date into 20120831 instead of 2012-08-31
					// date = std::stoi(dateStream.str());
					// return std::pair<int,float>(date, value);
}

