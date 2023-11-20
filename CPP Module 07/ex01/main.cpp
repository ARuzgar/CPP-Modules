#include <iostream>
#include <unistd.h>
#include "iter.hpp"

void print(int &a) {
	std::cout << a << std::endl;
}

void cast(int &a) {
	srand(time(0));
	a = rand() % 9 + 1;
	std::cout << "rand loading..." << std::endl;
	usleep(696969);
}

void add(int &a) {
	a += 1;
}

void printc(char &a) {
	std::cout << a << std::endl;
}

int main( void ) {
	int array[5] = {512, 213, 134, 1287, 123};
	std:: cout << "Array print with iter:" << std::endl;
	iter(array, 5, print);
	iter(array, 5, cast);
	std:: cout << "Array print with iter after rand cast with iter :" << std::endl;
	iter(array, 5, print);
	iter(array, 5, add);
	std:: cout << "Array print with iter after add with iter :" << std::endl;
	iter(array, 5, print);

	char array2[5] = {'a', 'b', 'c', 'd', 'e'};
	std:: cout << "char array print with iter:" << std::endl;
	iter(array2, 5, printc);


	return 0;
}