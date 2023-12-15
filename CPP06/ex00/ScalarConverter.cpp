#include "ScalarConverter.hpp"

bool isChar(const std::string& str) {
	if (str.length() != 1)
		return false; 
	char singleChar = str[0];
	return (!isdigit(singleChar) || isprint(singleChar));
}

bool isInt(const std::string& str){
	if(str.empty())
		return false;
	
	size_t startPos = 0;

	if(str[0] == '-' || str[0] == '+')
		startPos++;

	for(size_t i = startPos; i < str.length(); ++i){
		if(!isdigit(str[i]))
			return false;
	}

	long long overflow = atol(str.c_str());
	if(overflow > 2147483647 || overflow < -2147483648)
		return false;

	return true;
}

bool isDouble(const std::string& str){
	if(str.empty())
		return false;

	size_t startPos = 0;

	if(str[0] == '-' || str[0] == '+')
		startPos++;

	bool hasDecimal = false;

	for(size_t i = startPos; i < str.length(); ++i){
		if(isdigit(str[i]))
			continue;
		else if(str[i] == '.'){
			if(hasDecimal)
				return false;
			hasDecimal = true;
		}
		else 
			return false;
	}
	if(hasDecimal != true)
		return false;
	return true;
}

bool isFloat(const std::string& str){
	if(str.empty() || str[str.length() - 1] != 'f')
		return false;

	size_t startPos = 0;

	if(str[0] == '-' || str[0] == '+')
		startPos++;

	bool hasDecimal = false;

	for(size_t i = startPos; i < str.length() - 1; ++i){
		if(isdigit(str[i]))
			continue;
		else if(str[i] == '.'){
			if(hasDecimal)
				return false;
			hasDecimal = true;
		}
		else 
			return false;
	}
	if(hasDecimal != true)
		return false;
	return true;
}

bool	isPseudo(const std::string &str)
{
	std::string	pseudo[6] = {"inf", "-inf", "inff", "-inff", "nan", "nanf"};

	for (int i = 0; i < 6; i++)
	{
		if (str == pseudo[i])
			return (true);
	}
	return (false);
}

int checkType(const std::string& str) {
	if (isChar(str)) {
		return 1;
	} else if (isInt(str)) {
		return 2;
	} else if (isFloat(str)) {
		return 3;
	} else if (isDouble(str)) {
		return 4;
	} else if (isPseudo(str)){
		return 5;
	} else {
		return 6;
	}
}

void convertChar(const std::string& str) {
	char c = str.c_str()[0];
	std::cout << "Char: " << c << std::endl;
	std::cout << "integer: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void convertint(const std::string& str){
	int		i = atol(str.c_str());

	if (i < 32 || i >126)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout << "Char: " << static_cast<char>(i) << std::endl;
	std::cout << "Integer: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "Float: " << static_cast<float>(i) << "f" <<  std::endl;
	std::cout << "Double: " << static_cast<double>(i) <<  std::endl;
}

void convertDouble(const std::string& str){
	char	*end;
	double	d = strtod(str.c_str(), &end);
	if (d < 32.0 || d > 126.0)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout << "Char: " << static_cast<char>(d) << std::endl;
	if (d > 2147483647 || d < -2147483648)
		std::cout << "Integer: Impossible" << std::endl;
	else
	std::cout << "Integer: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Float: " << static_cast<float>(d) << "f" <<  std::endl;
	std::cout << "Double: " << d <<  std::endl;

}

void convertFloat(const std::string& str){
	char	*end;
	float	d = strtod(str.c_str(), &end);

	if (d < 32.0 || d > 126.0)
		std::cout << "Char: Non Displayable" << std::endl;
	else
		std::cout << "Char: " << static_cast<char>(d) << std::endl;
	if (d > 2147483647 || d < -2147483648)
		std::cout << "Integer: Impossible" << std::endl;
	else
	std::cout << "Integer: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed << std::setprecision(3);
	std::cout << "Float: " << d << "f" <<  std::endl;
	std::cout << "Double: " << static_cast<double>(d) <<  std::endl;

}

void	convertPseudo(const std::string &argument)
{
	char	*end;
	float	floatVal = std::atof(argument.c_str());
	double	doubleVal = strtod(argument.c_str(), &end);

	std::cout << "Char: Impossible" << std::endl;
	std::cout << "Integer: Impossible" << std::endl;
	std::cout << "Float: " << floatVal << 'f' << std::endl;
	std::cout << "Double: " << doubleVal << std::endl;
}


void ScalarConverter::converter(const std::string& str) {
	int result = checkType(str);

	switch (result) {
		case 1:
			convertChar(str);
			break;
		case 2:
			convertint(str);
			break;
		case 3:
			convertFloat(str);
			break;
		case 4:
			convertDouble(str);
			break;
		case 5:
			convertPseudo(str);
			break;
		default:
			std::cout << "Not recognized as any type" << std::endl;
			break;
	}

}