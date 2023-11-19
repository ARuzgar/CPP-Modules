#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		char chary;
		int inty;
		float floty;
		double douby;
		void ScalarConverter::CheckForEdge(std::string &str);
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();
		static void convert(std::string str);
		class InvalidInputException;
};

class ScalarConverter::InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif