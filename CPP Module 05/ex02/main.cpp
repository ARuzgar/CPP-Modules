#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 150);
	AForm *form;

	std::cout << scrclean << BLUE << std::endl << "PresidentialPardonForm" << RESET << std::endl;

	form = new PresidentialPardonForm("Jack Sparrow");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.signForm(*form);
	bureaucrat2.executeForm(*form);
	delete form;

	std::cout << BLUE << std::endl << "RobotomyRequestForm" << RESET << std::endl;

	form = new RobotomyRequestForm("Bureaucrat");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;

	std::cout << BLUE << std::endl << "ShrubberyCreationForm" << RESET << std::endl;

	form = new ShrubberyCreationForm("Home");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;
	
	return (0);

}