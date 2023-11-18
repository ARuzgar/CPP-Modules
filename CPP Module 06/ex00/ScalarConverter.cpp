#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &copy) {}

bool ScalarConverter::CheckForEdge(std::string str) {
	if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (true);
	return (false);
}

bool	ScalarConverter::convert(std::string str) {
	if (CheckForEdge(str))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << str << std::endl;
		std::cout << "double: " << str << std::endl;
		return (true);
	}
	
}