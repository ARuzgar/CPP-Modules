#include <Bureaucrat.hpp>

int main(void)
{
	Bureaucrat *newOfficer;
	newOfficer = new Bureaucrat("Can", 42);
	std::cout << newOfficer << std::endl;
	newOfficer->incrementGrade();
	std::cout << newOfficer << std::endl;
	newOfficer->decrementGrade();
	std::cout << newOfficer << std::endl;
	delete newOfficer;

	try{
		Bureaucrat busBoy("Badem", 151);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
		Bureaucrat busBoy("Badem", 150);
	try{
		busBoy.decrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	
		Bureaucrat busBoy("Badem", 1);
	try{
		busBoy.incrementGrade();
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}