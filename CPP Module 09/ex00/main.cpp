#include "BitcoinExchange.hpp"

//Add Comments
//Test file output number 5 is rounded up instead of down, check why
//Enrich the exception classes - Add more info to the exception via private variables
//Show some love to yourself honey

int main(int ac, char **av) {
	if (ac == 2) {
	    BitcoinExchange be;
		be.compareData(av[1]);
	}
	else
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
    return 0;
}