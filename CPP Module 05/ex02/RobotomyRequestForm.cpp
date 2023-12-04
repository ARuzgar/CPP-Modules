#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = "John Doe";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45) {
	this->target = target;

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) {
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
	std::cout << RESET << "Robotomy Request Form destroyed." << std::endl;
}

RobotomyRequestForm 	&RobotomyRequestForm::operator=(RobotomyRequestForm const &otherRobotomyRequestForm) {
	this->target = otherRobotomyRequestForm.getTarget();
	return (*this);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else
		this->action();
}

void	RobotomyRequestForm::action() const {
	std::cout << RESET << "Bzzz... drilling noises... Bzzz..." << std::endl;
	std::srand(std::time(0));
	if (rand() % 2)
		std::cout << RESET << this->target << " has been robotomized successfully." << std::endl;
	else
		std::cout << RESET << this->target << " robotomization has failed." << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
	return (this->target);
}