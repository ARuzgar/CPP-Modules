#ifndef CAT_HPP
# define CAT_HPP

# include <iostream>
# include "Animal.hpp"


class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &copy);
		Cat &operator=(Cat const &other);
		~Cat(void);
		void makeSound()const;
};

#endif