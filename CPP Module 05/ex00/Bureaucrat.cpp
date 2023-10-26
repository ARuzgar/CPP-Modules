#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	this->name = "john doe";
	this->grade = 150
}

Bureaucrat::Bureaucrat(const std::string &name, int grade){
	this->name = name;
	this->grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy){
	*this = copy;
}

Bureaucrat::~Bureaucrat(void){}

Bureaucrat &	Bureaucrat::operator=(Bureaucrat const &otherBureaucrat){
	this->name = otherBureaucrat.name;
	this->grade = otherBureaucrat.grade;
}

void	Bureaucrat::incrementGrade(){
	if(this->grade > 1 && this->grade <=150)
		this->grade--;
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(){
	if(this->grade < 150 && this->grade >= 1)
		this->grade++;
	else
		throw Bureaucrat::GradeTooLowException();
}

int	Bureaucrat::getGrade() const{
	return this->grade;
}

std::string	Bureaucrat::getName() const{
	return this->name;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}