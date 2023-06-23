#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal{
	public:
		Dog(void);
		Dog(Dog const &copy);
		Dog &operator=(Dog const &dog);
		~Dog();
		void makeSound() const;
};

#endif