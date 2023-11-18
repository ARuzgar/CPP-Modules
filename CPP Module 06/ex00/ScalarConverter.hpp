#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		static bool ScalarConverter::CheckForEdge(std::string str);
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter &copy);
		~ScalarConverter();
		static void convert(std::string str);
};

#endif