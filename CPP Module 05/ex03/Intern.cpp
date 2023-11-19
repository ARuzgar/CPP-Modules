#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy) {
	*this = copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy) {
	(void)copy;
	return *this;
}

AForm *Intern::makeForm(std::string formName, std::string target) {
	std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int formIndex = 0;
	while (formIndex < 3 && formName != forms[formIndex])
		formIndex++;
	switch (formIndex)
	{
		case 0:
			std::cout << RESET << "Intern creates " << formName << " form." << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << RESET << "Intern creates " << formName << " form." << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << RESET << "Intern creates " << formName << " form." << std::endl;
			return new PresidentialPardonForm(target);
		default:
			throw Intern::FormNotFoundException();
	}
}

const char *Intern::FormNotFoundException::what() const throw() {
	return "\033[31mForm not found.";
}