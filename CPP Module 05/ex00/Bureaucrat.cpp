#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void)
{
	this->name = "John Doe";
	this->grade = 150;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
	this->name = name;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
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
	if (this != &otherBureaucrat){
		this->name = otherBureaucrat.name;
		this->grade = otherBureaucrat.grade;
	}
	return (*this);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

std::string	Bureaucrat::getName() const
{
	return (this->name);
}

int	Bureaucrat::getGrade() const
{
	if (grade > 150)
		Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		Bureaucrat::GradeTooLowException();
	else
		return (this->grade);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bboy)
{

	output << bboy.getName() << " bureaucrat grade " << bboy.getGrade() << std::endl;
	return (output);
}
