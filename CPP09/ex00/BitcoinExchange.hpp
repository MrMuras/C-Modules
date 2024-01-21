#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fstream>
# include <stdexcept>
# include <sstream>
# include <string>

std::map<int, float> storedata();
std::pair<int, float>	checkline(std::string line);
void	handleinput(std::string file, std::map<int, float>);

#endif