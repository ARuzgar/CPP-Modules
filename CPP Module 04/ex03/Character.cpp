#include "Character.hpp"

Character::Character(std::string const & name)
{
	this->name = name;
	for(int i = 0; i < 4; i++)
			this->slots[i] = NULL;
	std::cout << name << "Has been born." << std::endl;
}

Character::Character(Character const &copy)
{
	*this = copy;
    std::cout << "Character " << this->name << " is getting cloned." << std::endl;
}

Character &	Character::operator=(Character const &other)
{
	this->name = other.name;
	for(int i = 0; i < 4; i++){
		if (this->slots[i]){
			delete this->slots[i];
		}
		this->slots[i] = other.slots[i];
	}
    std::cout << "Character " << this->name << " is cloned." << std::endl;
	return *this;
}

Character::~Character(){
	for(int i = 0; i < 4; i++){
		if(this->slots[i])
			delete this->slots[i];
	}
	std::cout << this->name << "has died." << std::endl;
}

void	Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if(!this->slots[i]){
			this->slots[i] = m;
			std::cout << "Materia " << m->getType() << " is equiped by " << this->name << std::endl;
			break;
		}
	}
}

std::string const & Character::getName() const{
	return this->name;
}

void	Character::unequip(int idx)
{
	if (this->slots[idx]){
		this->unequiped = this->slots[idx];
		std::cout << this->getName() << " unequiped " << this->slots[idx]->getType() << std::endl;
		this->slots[idx] = NULL;
	}
}

void	Character::use(int idx, ICharacter& target)
{
	if(this->slots[idx]){
		this->slots[idx]->use(target);
		std::cout << this->name << " is used " << this->slots[idx]->getType() << " on" << target.getName() << std::endl;
	}
}