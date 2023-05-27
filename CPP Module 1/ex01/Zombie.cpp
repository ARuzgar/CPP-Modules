#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::~Zombie(){
	std::cout << this->name << " got slayed." << std::endl;
}

void Zombie::setZombieName(std::string name){
	this->name = name;
}


void Zombie::announce(void){
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}