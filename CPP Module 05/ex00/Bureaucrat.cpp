#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->name = "John Doe";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, unsigned int grade)
{
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy)
{
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
	
}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &otherBureaucrat)
{
	this->name = otherBureaucrat.name;
	this->grade = otherBureaucrat.grade;
	return (*this);
}

std::ostream &operator<<(std::ostream &output, Bureaucrat &bboy)
{

	output << bboy.getName() << " bureaucrat grade " << bboy.getGrade() << std::endl;
	return (output);
}

void	Bureaucrat::gradeTooHighException()
{
	throw "highException";
}

void	Bureaucrat::gradeTooLowException()
{
	throw "lowException";
}

std::string	Bureaucrat::getName()
{
	return (this->name);
}

int	Bureaucrat::getGrade()
{
	if (grade > 150)
		gradeTooLowException;
	else if (grade < 1)
		gradeTooHighException;
	else
		return (this->grade);
}