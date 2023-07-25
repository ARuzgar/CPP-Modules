#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include "Brain.hpp"

class Animal
{
	protected:
		std::string type;
		
	public:
		Animal(void);
		Animal(Animal const &copy);
		Animal &operator=(Animal const &otherAnimal);
		virtual ~Animal(void);

		virtual void makeSound() const;
		std::string getType() const;
};

#endif