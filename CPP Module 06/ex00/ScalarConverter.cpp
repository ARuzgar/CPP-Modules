#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &	ScalarConverter::operator=(const ScalarConverter &copy) {}

void ScalarConverter::CheckForEdge(std::string str) {
		std::cout << "char: " << this->chary << std::endl;
		std::cout << "int: " << this->inty << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << this->floty << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << this->douby << std::endl;

}

void	ScalarConverter::convert(std::string str) {
	try
	{
		ScalarConverter::CheckForEdge(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	

}

const char* ScalarConverter::InvalidInputException::what() const throw() {
	return ("Invalid Input.");
}