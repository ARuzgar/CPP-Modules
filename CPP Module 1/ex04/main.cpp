#include <iostream>
#include <fstream>
//testing


int main(int ac, char **av) {
	if (ac == 4)
	{
		std::string theAdress = av[1];
		std::string theAdress = av[1] + ;
		std::string oldWord = av[2];
		std::string newWord = av[3];
		std::string holder;
		std::ifstream inFile(theAdress);
		std::ofstream outFile();

		if (inFile.fail()) {
			std::cerr << "Failed to open the file." << std::endl;
			exit (1);
		}
		
		while (inFile >> holder) {
			std::cout << holder << std::endl;
		}
	}
	else
		std::cout << "Insufficent Arguments. Please follow the template : ./replace [filename/fileadress] [the word to be replaced] [the word to replace]" << std::endl;
	return 0;
}
