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
		static uintptr_t serialize(Data *data);
		static Data *deserialize(uintptr_t raw);
		static void printData(Data *data);
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