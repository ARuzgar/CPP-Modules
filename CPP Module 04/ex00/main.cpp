#include "Dog.hpp"
#include "Cat.hpp"

#include "WrongCat.hpp"

int main( void )
{
    std::cout << "--------------- Animal ---------------" << std::endl;

    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete  j;
    delete  i;
    delete  meta;

    std::cout << std::endl << "------------- Wrong Animal -------------" << std::endl;

    const WrongAnimal *wrong = new WrongCat();
    const WrongCat *wrongCat = new WrongCat();

    std::cout << "Wrong Type: " << wrong->getType() << " " << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    wrong->makeSound();
    wrongCat->makeSound();

    delete  wrong;
    delete  wrongCat;

    return 0;
}