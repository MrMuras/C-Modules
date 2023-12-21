#include "BitcoinExchange.hpp"
// usless crap
BitcoinExchange::BitcoinExchange(){}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy):_dataMap(copy._dataMap){}
BitcoinExchange::BitcoinExchange(std::string inputFile) : _input(inputFile){} // not you
BitcoinExchange::~BitcoinExchange(){
	std::cout << "\e[0;31mDestructor called of BitcoinExchange\e[0m" << std::endl;}
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &assign){
	_dataMap = assign._dataMap;
	return *this;}
// end of usless crap


