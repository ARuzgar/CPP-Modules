#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation Form", 145, 137) {
	this->target = "John Doe";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation Form", 145, 137) {
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) {
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	std::cout << RESET << "Shrubbery Creation Form destroyed." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &otherShrubberyCreationForm) {
	if (this != &otherShrubberyCreationForm)
		this->target = otherShrubberyCreationForm.getTarget();
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	else if (!this->getSign())
		throw AForm::FormNotSignedException();
	else
		this->action();
}

void	ShrubberyCreationForm::action() const {
	std::ofstream file;
	file.open(this->target + "_shrubbery");
	file << "               1\n";
    file << "             /   \\\n";
    file << "           1       2\n";
    file << "         /   \\   /   \\\n";
    file << "        1     3 3     2\n";
    file << "       / \\   / \\   /   \\\n";
    file << "      1   4 4   5 5     2\n";
    file << "     / \\           / \\   / \\\n";
    file << "    1   5         6   7 7   2\n";
    file << "   / \\                   / \\\n";
    file << "  1   6                 8   9\n";
    file << " / \\\n";
    file << "1   7\n";
}

std::string	ShrubberyCreationForm::getTarget() const {
	return (this->target);
}