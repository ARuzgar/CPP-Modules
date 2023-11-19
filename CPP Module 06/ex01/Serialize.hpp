#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <cmath>
# include <limits>
# include <sstream>
# include <exception>
# include <cctype>

class Serializer
{
	private:
		struct Data;
		static void *serialize(void);
		static Data *deserialize(void *raw);
		static std::string randomString(int len);
		static int randomInt(void);
		static char randomChar(void);
		static void printData(Data *data);
		static void printRaw(void *raw);
		static std::string integerToString(int n);
	public:
		Serializer();
		~Serializer();
		static void test(void);
};

struct Serializer::Data
{
	std::string s1;
	int n;
	std::string s2;
};

#endif