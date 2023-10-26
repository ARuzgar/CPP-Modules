#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat newOfficer("Can", 42);
	std::cout << newOfficer << std::endl;
	newOfficer.incrementGrade();
	std::cout << newOfficer << std::endl;
	newOfficer.decrementGrade();
	std::cout << newOfficer << std::endl;

	try{
		Bureaucrat busBoy("Badem", 151);
	}
	catch (std::exception & paperWork)
	{
		std::cout << paperWork.what() << std::endl;
	}
		Bureaucrat busBoy("Badem", 150);
	try{
		busBoy.decrementGrade();
	}
	catch (std::exception & paperWork)
	{
		std::cout << paperWork.what() << std::endl;
	}
	
		Bureaucrat manager("Badem", 1);
	try{
		manager.incrementGrade();
	}
	catch (std::exception & paperWork)
	{
		std::cout << paperWork.what() << std::endl;
	}
}