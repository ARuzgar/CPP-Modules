#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat("Bureaucrat", 1);
	Bureaucrat bureaucrat2("Bureaucrat2", 150);
	Form form;

	bureaucrat.signForm(form);
	bureaucrat2.signForm(form);
}