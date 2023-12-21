#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		// usless constructors
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &copy);
		BitcoinExchange(std::string);
		~BitcoinExchange();
		BitcoinExchange & operator=(const BitcoinExchange &assign);
		// usefull functions

	private:
		std::map<std::string, float> _dataMap;
		std::string _input;
		
};

#endif