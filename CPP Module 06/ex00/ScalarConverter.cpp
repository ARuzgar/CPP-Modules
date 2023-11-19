#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	chary = 0;
	inty = 0;
	floty = 0;
	douby = 0;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &copy) {}

int ScalarConverter::checkForEdge(std::string str) {
	std::string edges[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};
	int edgeIndex = 0;
	while (edgeIndex < 8 && str != edges[edgeIndex])
		edgeIndex++;
	switch (edgeIndex)
	{
		case 0:
			
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return 1;
		case 1:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: nanf" << std::endl;
			std::cout << "double: nan" << std::endl;
			return 1;
		case 2:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return 1;
		case 3:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: -inff" << std::endl;
			std::cout << "double: -inf" << std::endl;
			return 1;
		case 4:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return 1;
		case 5:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return 1;
		case 6:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return 1;
		case 7:
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: +inff" << std::endl;
			std::cout << "double: +inf" << std::endl;
			return 1;
		default:
			return 0;
	}
}

int ScalarConverter::checkCharAndDigits(std::string str)
{
	if(str.length() > 1)
		return 0;
	else
	{
		if (!isdigit(str[0]))
		{
			chary = static_cast<char>(str[0]);
			inty = static_cast<int>(chary);
			floty = static_cast<float>(chary);
			douby = static_cast<double>(chary);
			return 1;
		}
		else if(isdigit(str[0]))
		{
			inty = static_cast<int>((str[0] - '0'));
			chary = static_cast<char>(inty);
			floty = static_cast<float>(inty);
			douby = static_cast<double>(inty);
			return 1;
		}
	}
}

int ScalarConverter::checkFloat(std::string str)
{
	floty = std::strtod(str);

	if 
}

int ScalarConverter::checkInt(std::string str)
{
	std::istringstream iss(str);

	if (iss >> inty)
	{
		chary = static_cast<char>(inty);
		floty = static_cast<float>(inty);
		douby = static_cast<double>(inty);
		return 1;
	}
	else
		return 0;
}

int ScalarConverter::findType(std::string str)
{
	if (checkCharAndDigits(str) || checkInt(str) || checkFloat(str) || checkDouble(str))
		return 1;
	else
		return 0;
}

void	ScalarConverter::convert(std::string str) {
	if(ScalarConverter::checkForEdge(str))
		return;
	else if (findType(str))
	{
		std::cout << "char: " << chary << std::endl;
		std::cout << "int: " << inty << std::endl;
		std::cout << "float: " << std::setprecision(2) << floty << "f" << std::endl;
		std::cout << "double: " << std::setprecision(2) << douby << std::endl;
	}
	else
		throw(ScalarConverter::InvalidInputException());
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return ("Invalid Input");
}
