#include "WrongAnimal.hpp"

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType() const {
    return this->type;
}