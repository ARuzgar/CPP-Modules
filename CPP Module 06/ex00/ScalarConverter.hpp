#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>
# include <sstream>
# include <exception>
# include <cctype>


class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();

		static int inty;
		static float floty;
		static double douby;
		static char chary;
		static int a;

		static int checkDouble(std::string str);
		static int checkFloat(std::string str);
		static int checkInt(std::string str);
		static int checkCharAndDigits(std::string str);
		static int checkForNaN(std::string str);
		static int findType(std::string str);
		static int checkIntEdge(std::string str); 
		static int checkNanEdge(std::string str); 
	public:
		static void convert(std::string str);
		class InvalidInputException;
};

class ScalarConverter::InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#endif