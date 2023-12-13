#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	if (ac == 2) {
	    BitcoinExchange be;
		be.compareData(av[1]);
	}
	else
		std::cout << "Usage: ./bitcoin [file]" << std::endl;
    return 0;
}