# include "AForm.hpp"

AForm::AForm(void) : name("AForm"), gradeToSign(150), gradeToExecute(150), sign(false) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), sign(false) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
}

AForm::AForm(AForm const &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	*this = copy;
}

AForm &AForm::operator=(AForm const &otherAForm) {
	this->sign = otherAForm.sign;
	return *this;
}

AForm::~AForm(void) {}

std::string	AForm::getName() const{
	return this->name;
}

bool		AForm::getSign() const{
	return this->sign;
}

int			AForm::getGradeToSign() const{
	return this->gradeToSign;
}

int			AForm::getGradeToExecute() const{
	return this->gradeToExecute;
}

void		AForm::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign)
		this->sign = true;
	else
		throw AForm::GradeTooLowException();
}

void		AForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() > this->gradeToExecute)
		throw AForm::GradeTooLowException();
	else if (!this->sign)
		throw AForm::FormNotSignedException();
	else
		this->action();
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "\033[31mForm is not signed!";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "\033[31mGrade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "\033[31mGrade is too low!";
}

std::ostream &operator<<(std::ostream &output, const AForm &form) {
	output << RESET << form.getName() << " form is";
	if (form.getSign())
		output << RESET << " signed. This form requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	else
		output << RESET << " not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	return output;
}