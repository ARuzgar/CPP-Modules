#include "Brain.hpp"

Brain::Brain(void){ 
	std::cout << "Brain is constructed." << std::endl;
	std::stringstream thoughtNumber;
	std::string treatNum;
	for (int j = 0; j < 100; j++){
		thoughtNumber << j;
		thoughtNumber >> treatNum;
		this->Ideas[j] = "I need to eat " + treatNum + " treats!";
	}
}

Brain::Brain(Brain const &copy){
	std::cout << "Brain copy constructor called." << std::endl;
	*this = copy;
}

Brain &	Brain::operator=(Brain const &otherBrain){
	std::cout << "Other Brain is clonned." << std::endl;
	for (int j = 0; j < 100; j++)
		this->Ideas[j] = otherBrain.Ideas[j];
	return (*this);
}

Brain::~Brain(void){
	std::cout << "A Brain destructed." << std::endl;
}

std::string	*	Brain::getIdeas(void){
	return this->Ideas;
}

std::string	Brain::getIdea(int j) const{
	return this->Ideas[j];
}