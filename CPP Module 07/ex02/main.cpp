#include "Array.hpp"

int main(void)
{
	Array<int> a(5);
	Array<char> b(5);
	Array<float> c(5);

	for (unsigned int i = 0; i < a.size(); i++)
		a[i] = i;

	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = 'a' + i;
	
	for (unsigned int i = 0; i < c.size(); i++)
		c[i] = i + 0.5;
	
	for (unsigned int i = 0; i < a.size(); i++)
		std::cout << a[i] << std::endl;
	
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << b[i] << std::endl;

	for (unsigned int i = 0; i < c.size(); i++)	
		std::cout << c[i] << std::endl;
	
	try {
		std::cout << a[10] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << a[-1] << std::endl;
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}