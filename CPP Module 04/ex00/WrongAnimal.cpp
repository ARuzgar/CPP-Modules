#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type( "WrongAnimal" ) {
    std::cout << this->type << " constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( std::string type ) : type( type ) {
    std::cout << "WrongAnimal " << this->type << " constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& copy ) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if ( this != &other ) {
        this->type = other.type;
    }
    return *this;
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal makeSound called" << std::endl;
}

std::string    WrongAnimal::getType() const {
    return this->type;
}