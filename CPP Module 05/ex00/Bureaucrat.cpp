#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : name("John Doe"), grade(150) {
	std::cout << RESET << "Hurraay " << this->name << " has been hired!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	std::cout << RESET << "Hurraay " << this->name << " has been hired!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : name(copy.name) {
	std::cout << RESET << "A new trainee assigned to " << copy.getName() << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &otherBureaucrat) {
	this->grade = otherBureaucrat.grade;
	std::cout << RESET << "New trainee literally turned into a copy of " << otherBureaucrat.getName() << std::endl;
	return *this;
}

void	Bureaucrat::incrementGrade() {
	if(this->grade > 1 && this->grade <=150){
		this->grade--;
		std::cout << RESET << this->name << " got promoted!" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if(this->grade < 150 && this->grade >= 1){
		this->grade++;
		std::cout << RESET << this->name << " got demoted..." << std::endl;
	}
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
	return "\033[31mGrade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "\033[31mGrade too low";
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureuaucrat) {
	output << RESET << bureuaucrat.getName() << ", bureaucrat grade " << bureuaucrat.getGrade();
	return output;
}