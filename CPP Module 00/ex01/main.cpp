#include "PhoneBook.hpp"
//take care of dolphins
PhoneBook phonebook;

std::string ftToUpper(std::string command)
{
	std::string upper;
	for (unsigned long i = 0; i < command.length(); i++){
		char c = std::toupper(command[i]);
		upper += c;
	}
	return upper;
}

void	parser(std::string command, std::string cap)
{

	if (command == "EXIT")
			exit (0);
	else if (command == "ADD")
	{
		phonebook.addContact();
		phonebook.initInterface();
		std::cout << "\033[3;31mᴰᴱₗᴵᶜᴵₒᵁₛ! ᴬₕᴬₕᴬₕᴬ" <<std::endl;
	}
	else if (command == "SEARCH")
	{
		phonebook.initInterface();
		phonebook.displayContact();
	}
	else if (command == "add" || command == "search" || command == "exit" || command == "Add" || command == "Search" || command == "Exit"){
		phonebook.initInterface();
		std::cout << cap << "Did you mean : \"" << ftToUpper(command) << "\" ? (It's annoying, right? I know...)" << std::endl;
	}
	else{
		phonebook.initInterface();
		if (!command.empty())
			std::cout << cap << "Invalid Command : " << command << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac > 1)
		exit (0);
	(void)av;
	std::string	command;
	std::string	cap = phonebook.initInterface();
	while (1) {
		std::cout << cap;
		std::getline(std::cin, command);
		parser(command,cap);
	}  
	return 0;
}
