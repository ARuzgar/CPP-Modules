#include <iostream>
#include <fstream>

int main(int ac, char **av) {
	if (ac == 4)
	{
		std::string theAdress = av[1];
		std::string oldWord = av[2];
		std::string newWord = av[3];
		std::string wholeLine;
		std::string holder;
		std::ifstream inFile(theAdress);
		size_t where;

		if (inFile.fail()) {
			std::cerr << "Failed to open the file." << std::endl;
			exit (1);
		}

		std::ofstream outFile(theAdress + ".replace", std::ios::trunc);
		if (outFile.fail()) {
			std::cerr << "Failed to open the file." << std::endl;
			exit (2);
		}
		while (std::getline(inFile, wholeLine)){
			where = 0;
			holder = wholeLine;
			while ((where = wholeLine.find(oldWord, where)) != std::string::npos)
			{
				holder.erase(where, oldWord.length());
				holder.insert(where, newWord);
				where += newWord.length();
			}
		outFile << holder << std::endl;
	}
	}
	else
		std::cout << "Insufficent/Wrong Arguments. Please follow the template : ./replace [filename/fileadress] [the word to be replaced] [the word to replace]" << std::endl;
	return 0;
}
