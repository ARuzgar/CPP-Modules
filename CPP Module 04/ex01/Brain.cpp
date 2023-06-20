#include "Brain.hpp"

Brain::Brain(void)
{ 
	std::cout << "Brain is constructed." << std::endl;
	std::stringstream thoughtNumber;
	std::string bowlNum;
	for (int j = 0; j < 100; j++){
		thoughtNumber << j;
		thoughtNumber >> bowlNum;
		this->Ideas[j] = "I need to eat " + bowlNum + " treats!";
	}
}


Brain::~Brain(void)
{
	std::cout << "A Brain destructed." << std::endl;
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = copy;
}

Brain &	Brain::operator=(Brain const &brain)
{
	for (int j = 0; j < 100; j++)
		this->Ideas[j] = brain.Ideas[j];
	return (*this);
}

std::string *	Brain::getIdeas()
{
	return this->Ideas;
}

std::string	Brain::getIdea(int j) const
{
	return this->Ideas[j];
}