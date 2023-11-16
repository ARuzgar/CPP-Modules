#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat newOfficer("Ruru", 42);
	std::cout << newOfficer << std::endl;
	newOfficer.incrementGrade();
	std::cout << newOfficer << std::endl;
	newOfficer.decrementGrade();
	std::cout << newOfficer << std::endl;

	try{
		Bureaucrat busBoy("Badem", 151);
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}
	
	Bureaucrat busBoy("Iro", 150);
	try{
		busBoy.decrementGrade();
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}
	
	Bureaucrat manager("Iro", 1);
	try{
		manager.incrementGrade();
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}

	Form form("Form", 42, 42);
	std::cout << form << std::endl;
	try{
		Form form("Form", 151, 42);
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}
	try{
		Form form("Form", 42, 151);
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}
	try{
		Form form("Ihale", 42, 42);
		Bureaucrat newOfficer("Ruru", 42);
		std::cout << form << std::endl;
		newOfficer.incrementGrade();
		form.beSigned(newOfficer);
		newOfficer.signForm(form.getName(), form.getSign());
		std::cout << form << std::endl;
	}
	catch (std::exception & paperWork)	{
		std::cout << paperWork.what() << std::endl;
	}
}