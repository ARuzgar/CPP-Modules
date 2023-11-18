#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) {
	this->name = "John Doe";
	this->grade = 150;
	std::cout << "Hurraay " << this->name << " has been hired!" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) {
	this->name = name;
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade = grade;
	std::cout << "Hurraay " << this->name << " has been hired!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {
	std::cout << "A new trainee assigned to " << copy.getName() << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &otherBureaucrat) {
	this->name = otherBureaucrat.name;
	this->grade = otherBureaucrat.grade;
	std::cout << "New trainee literally turned into a copy of " << otherBureaucrat.getName() << std::endl;
	return *this;
}

void	Bureaucrat::incrementGrade() {
	if(this->grade > 1 && this->grade <=150){
		this->grade--;
		std::cout << this->name << " got promoted!" << std::endl;
	}
	else
		throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade() {
	if(this->grade < 150 && this->grade >= 1){
		this->grade++;
		std::cout << this->name << " got demoted..." << std::endl;
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

void	Bureaucrat::signForm(AForm &form) {
	if (form.getSign())
		std::cout << this->name << " cannot sign " << form.getName() << " because it's already signed." << std::endl;
	else if (this->grade <= form.getGradeToSign()) {
		form.beSigned(*this);
		std::cout << this->name << " signs " << form.getName() << std::endl;
	}
	else
		std::cout << this->name << " cannot sign " << form.getName() << " because he's grade insufficent." << std::endl;
}

void 		Bureaucrat::executeForm(AForm const & form) {
	if (!form.getSign())
		std::cout << this->name << " cannot execute " << form.getName() << " because it's not signed." << std::endl;
	else if (this->grade <= form.getGradeToExecute()) {
		std::cout << this->name << " executed " << form.getName() << std::endl;
		form.execute(*this);
	}
	else
		std::cout << this->name << " cannot execute " << form.getName() << " because he's grade insufficent." << std::endl;

}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureuaucrat) {
	output << bureuaucrat.getName() << ", bureaucrat grade " << bureuaucrat.getGrade();
	return output;
}