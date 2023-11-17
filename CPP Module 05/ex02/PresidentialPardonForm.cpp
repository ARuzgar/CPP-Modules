#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon Form", 25, 5)  {
	this->target = "John Doe";
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon Form", 25, 5) {
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) {
	std::cout << "Presidential Pardon has been copied." << std::endl;
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
	std::cout << "Presidential Pardon has been destroyed." << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &otherPresidentialPardonForm) {
	std::cout << "Presidential Pardon has been assigned." << std::endl;
	if (this != &otherPresidentialPardonForm)
		this->target = otherPresidentialPardonForm.target;
	return (*this);
	
}

void	PresidentialPardonForm::action() const {
	std::cout << this->target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}

std::string	PresidentialPardonForm::getTarget() const {
	return (this->target);
}
