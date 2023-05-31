#include "Harl.hpp"

void Harl::debug(void){
	std::cout << "\n[ DEBUG ]\n\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!\n" << std::endl;
}

void Harl::info(void){
	std::cout << "[ INFO ]\n\nI cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n" << std::endl;
}

void Harl::warning(void){
	std::cout << "[ WARNING ]\n\nI think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month.\n" << std::endl;
}

void Harl::error(void){
	std::cout << "[ ERROR ]\n\nThis is unacceptable!\nI want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level){
	pToFunc funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};	
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*funcs[i])();
	}
}