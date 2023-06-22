# ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	virtual			~WrongAnimal();
	virtual void	makeSound() const = 0;
	std::string		getType() const; 
};

#endif