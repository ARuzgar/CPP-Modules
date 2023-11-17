#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 150);
	AForm *form;

	form = new PresidentialPardonForm("Jack Sparrow");
	std::cout << *form << std::endl;
	bureaucrat.signForm(*form);
	bureaucrat.signForm(*form);
	bureaucrat.executeForm(*form);
	bureaucrat2.executeForm(*form);
	bureaucrat2.signForm(*form);
	delete form;

	
	return (0);

}