#ifndef DOG_HPP
# define DOG_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal{

	private :
		Brain	*brain;

	public:
		Dog();
		Dog(const Dog &copy);
		Dog &operator=(const Dog &otherDog);
		~Dog();

		void makeSound() const;
};

#endif