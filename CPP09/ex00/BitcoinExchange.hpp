#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <stdexcept>
# include <sstream>
# include <string>

std::map<std::string, float> storedata();
void	checkline(std::string line);
void	handleinput(std::string file);

#endif