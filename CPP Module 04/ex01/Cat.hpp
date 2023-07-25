#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
	private :
		Brain	*brain;

	public:
		Cat();
		Cat(const Cat &copy);
		Cat &operator=(const Cat &otherCat);
		~Cat();

		void makeSound() const;
};

#endif