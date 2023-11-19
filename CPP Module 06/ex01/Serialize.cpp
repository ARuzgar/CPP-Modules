#include "Serialize.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

void Serializer::test(void)
{
	uintptr_t raw;
	Data *data = new Data;
	Data *data2;
	raw = serialize(data);
	data2 = deserialize(raw);
	printData(data2);
}

uintptr_t Serializer::serialize(Data* data)
{
	uintptr_t raw = 0;
	std::cout << "Serializing started" << std::endl;
	data->s1 = "Hello there!";
	data->n = 42;
	data->s2 = "General Kenobi!";
	std::cout << std::endl << "Data point is : " << data << std::endl;
	std::cout << "Data content is : " << std::endl << data->s1 << std::endl
			<< data->n << std::endl
			<< data->s2 << std::endl;
	raw = reinterpret_cast<uintptr_t>(data);
	std::cout << "Raw data is : " << raw << std::endl << std::endl;
	return (raw);
}

Serializer::Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data;
	std::cout << std::endl << "Deserializing started" << std::endl;
	data = reinterpret_cast<Data *>(raw);
	return (data);
}

void Serializer::printData(Data *data)
{
	std::cout << "Data 2 point is : " << data << std::endl;
	std::cout << "Data 2 content is : " << std::endl << data->s1 << std::endl
			<< data->n << std::endl
			<< data->s2 << std::endl;
}