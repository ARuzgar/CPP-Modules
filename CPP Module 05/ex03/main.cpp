#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm *rrf;
	AForm *scf;
	AForm *ppf;
	AForm *unknown;

	try
	{
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		scf = someRandomIntern.makeForm("shrubbery creation", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		ppf = someRandomIntern.makeForm("presidential pardon", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		unknown = someRandomIntern.makeForm("unknown", "Bender");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat b1("Bureaucrat 1", 1);
	Bureaucrat b2("Bureaucrat 2", 150);

	b1.signForm(*rrf);
	b1.executeForm(*rrf);
	b1.signForm(*scf);
	b1.executeForm(*scf);
	b1.signForm(*ppf);
	b1.executeForm(*ppf);
	b2.signForm(*rrf);
	b2.executeForm(*rrf);
	b2.signForm(*scf);
	b2.executeForm(*scf);
	b2.signForm(*ppf);
	b2.executeForm(*ppf);

	delete rrf;
	delete scf;
	delete ppf;
	(void)unknown;

	return (0);

}