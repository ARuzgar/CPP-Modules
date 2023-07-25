#include "Character.hpp"

//Constructor
Character::Character(std::string const & name)
{
	this->name = name;
	for(int i = 0; i < 4; i++)
			this->slots[i] = NULL;
	std::cout << name << " has been born." << std::endl;
}

//Copy Constructor a.k.a. Function Overload
Character::Character(Character const &copy)
{
	if(this->name != "")
	    std::cout << "Character " << this->name << " is cloning " << copy.getName() << std::endl;
	else
	    std::cout << "Character " << copy.getName() << " is getting cloned." << std::endl;

	*this = copy;
}

//Operator Overload, Deep Copies slots via Clone Method of Materia's.
Character &	Character::operator=(Character const &otherCharacter)
{
	this->name = otherCharacter.name;
	for(int i = 0; i < 4; i++){
		if (this->slots[i]){
			delete this->slots[i];
		}
		this->slots[i] = otherCharacter.slots[i]->clone();
	}
    std::cout << "Character " << this->name << " is cloned." << std::endl;
	return *this;
}

//Destructor
Character::~Character(){
	for(int i = 0; i < 4; i++){
		if(this->slots[i])
			delete this->slots[i];
	}
	std::cout << this->name << " has died." << std::endl;
}

//For getting Materia's to empty slots
void	Character::equip(AMateria* m){
	for(int i = 0; i < 4; i++){
		if(!this->slots[i]){
			this->slots[i] = m;
			std::cout << "Materia " << m->getType() << " is equiped by " << this->name << std::endl;
			break;
		}
	}
}

//Setter-Getter's Getter
std::string const & Character::getName() const{
	return this->name;
}

//For leaving the Materia thats on idx numbered slot to the ground.
void	Character::unequip(int idx)
{
	if (this->slots[idx]){
		this->unequiped = this->slots[idx];
		std::cout << this->getName() << " unequiped " << this->slots[idx]->getType() << std::endl;
		this->slots[idx] = NULL;
	}
}

//Use the materia thats on idx numbered slot on the target
void	Character::use(int idx, ICharacter& target)
{
	if(this->slots[idx]){
		std::cout << this->name << " is used " << this->slots[idx]->getType() << " on " << target.getName() << std::endl;
		this->slots[idx]->use(target);
	}
}