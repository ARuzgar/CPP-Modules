#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 150);
	Form form;
	std::cout << scrclean << MAGENTA << "Form Errors" << RESET << std::endl;
	try {
		Form form1("Formula", 151, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form2("Formula", 1, 151);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form3("Formula", 0, 1);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Form form4("Formula", 1, 0);
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << MAGENTA << "Formal stuff, get it ? lol" << RESET << std::endl;
	Form form6("Formula", 1, 1);
	bureaucrat.signForm(form);
	bureaucrat2.signForm(form);
	bureaucrat2.signForm(form6);
	std::cout << form << std::endl;
	std::cout << form6 << std::endl;
}