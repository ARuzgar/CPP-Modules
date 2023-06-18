#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "\n[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" << std::endl;
}

void Harl::info(void){
	std::cout << "\n[ INFO ]\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning(void){
	std::cout << "\n[ WARNING ]\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void){
	std::cout << "\n[ ERROR ]\nThis is unacceptable!\nI want to speak to the manager now.\n" << std::endl;
}

void Harl::complain(std::string level){
	std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int levelIndex = 0;
	while (levelIndex < 4 && level != levels[levelIndex])
		levelIndex++;
	switch (levelIndex)
	{
		case 0:
			debug();
		case 1:
			info();
		case 2:
			warning();
		case 3:
			error();
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}