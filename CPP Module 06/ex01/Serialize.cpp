#include "Serialize.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

void Serializer::printRaw(void *raw)
{
	int i = 0;

	std::cout << "Printing the raw data" << std::endl;
	while (i < 20)
	{
		std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)reinterpret_cast<char *>(raw)[i];
		i++;
	}
	std::cout << std::endl;
	std::cout << "Raw data has been printed!" << std::endl;
}

void Serializer::test(void)
{
	void *raw;
	Data *data;

	raw = serialize();
	printRaw(raw);
	data = deserialize(raw);
	printData(data);
	delete reinterpret_cast<char *>(raw);
	delete data;
}

void *Serializer::serialize(void)
{
	char *raw = new char[20];
	int i = 0;
	int j = 0;

	std::cout << "Serializing started" << std::endl;
	std::string s1 = "easypeasy";
	std::cout << "String s1 is : " << s1 << std::endl;
	while (i < 9)
	{
		raw[i] = s1[i];
		i++;
	}
	std::string s2 = "lemonsquezy";
	std::cout << "String s2 is : " << s2 << std::endl;
	j = 0;
	while (i < 20 && j < 11)
	{
		raw[i] = s2[j];
		i++;
		j++;
	}
	std::cout << "Serialization is done!" << std::endl;
	return (raw);
}

Serializer::Data *Serializer::deserialize(void *raw)
{
	Data *data = new Data;
	int i = 0;

	std::cout << "Deserializing started" << std::endl;
	std::cout << "Deserializing the first string" << std::endl;
	while (i < 9)
	{
		data->s1 += reinterpret_cast<char *>(raw)[i];
		i++;
	}
	std::cout << "Deserialized string is : " << data->s1 << std::endl;
	std::cout << "Deserializing the second string" << std::endl;
	while (i < 20)
	{
		data->s2 += reinterpret_cast<char *>(raw)[i];
		i++;
	}
	std::cout << "Deserialized string is : " << data->s2 << std::endl;
	std::cout << "Deserialization is done!" << std::endl;
	return (data);
}

void Serializer::printData(Data *data)
{
	std::cout << "Data Includes : " << std::endl;
	std::cout << "First String: " << data->s1 << std::endl;
	std::cout << "Second String: " << data->s2 << std::endl;
}
