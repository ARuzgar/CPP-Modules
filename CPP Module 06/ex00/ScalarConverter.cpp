#include "ScalarConverter.hpp"

char ScalarConverter::chary = 0;
int ScalarConverter::inty = 0;
float ScalarConverter::floty = 0.0f;
double ScalarConverter::douby = 0.0;

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
	(void)copy;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &copy) {
	(void)copy;
	return *this;
}

int ScalarConverter::checkForEdge(std::string str) {
	std::string edges[] = {"nan", "nanf", "-inf", "-inff", "+inf", "+inff", "inf", "inff"};
	int edgeIndex = 0;
	while (edgeIndex < 8 && str != edges[edgeIndex])
		edgeIndex++;
	switch (edgeIndex)
	{
		case 0:
			
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: nanf" << std::endl
			<< "double: nan" << std::endl;
			return 1;
		case 1:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: nanf" << std::endl
			<< "double: nan" << std::endl;
			return 1;
		case 2:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: -inff" << std::endl
			<< "double: -inf" << std::endl;
			return 1;
		case 3:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: -inff" << std::endl
			<< "double: -inf" << std::endl;
			return 1;
		case 4:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: +inff" << std::endl
			<< "double: +inf" << std::endl;
			return 1;
		case 5:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: +inff" << std::endl
			<< "double: +inf" << std::endl;
			return 1;
		case 6:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: +inff" << std::endl
			<< "double: +inf" << std::endl;
			return 1;
		case 7:
			std::cout << "char: impossible" << std::endl
			<< "int: impossible" << std::endl
			<< "float: +inff" << std::endl
			<< "double: +inf" << std::endl;
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
		}
		else if(isdigit(str[0]))
		{
			inty = static_cast<int>((str[0] - '0'));
			chary = static_cast<char>(inty);
			floty = static_cast<float>(inty);
			douby = static_cast<double>(inty);
		}
		return 1;
	}
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

int ScalarConverter::checkFloat(std::string str)
{
	char* end;
	floty = std::strtof(str.c_str(), &end);

	if (*end != '\0')
		return 0;
	else
	{
		inty = static_cast<int>(floty);
		chary = static_cast<char>(floty);
		douby = static_cast<double>(floty);
		return 1;
	} 
}

int ScalarConverter::checkDouble(std::string str)
{
	char* end;
	floty = std::strtod(str.c_str(), &end);

	if (*end != '\0')
		return 0;
	else
	{
		inty = static_cast<int>(floty);
		chary = static_cast<char>(floty);
		douby = static_cast<double>(floty);
		return 1;
	} 
}

int ScalarConverter::findType(std::string str)
{
	if (checkCharAndDigits(str) || checkInt(str) || checkFloat(str) || checkDouble(str))
		return 1;
	else
		return 0;
}

void	ScalarConverter::convert(std::string str) {
	if(checkForEdge(str))
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
