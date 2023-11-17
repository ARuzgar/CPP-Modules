#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 150);
	AForm *form;

	std::cout << std::endl << "PresidentialPardonForm" << std::endl;

	form = new PresidentialPardonForm("Jack Sparrow");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;

	std::cout << std::endl << "RobotomyRequestForm" << std::endl;

	form = new RobotomyRequestForm("Bender");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;

	std::cout << std::endl << "ShrubberyCreationForm" << std::endl;

	form = new ShrubberyCreationForm("Home");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;
	
	return (0);

}