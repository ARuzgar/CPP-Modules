# include "Form.hpp"

Form::Form() : name("Form"), gradeToSign(150), gradeToExecute(150), sign(false) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) : name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), sign(false) {
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
}

Form::Form(Form const &copy) : name(copy.name), gradeToSign(copy.gradeToSign), gradeToExecute(copy.gradeToExecute) {
	*this = copy;
}

Form &Form::operator=(Form const &otherForm) {
	this->sign = otherForm.sign;
	return *this;
}

Form::~Form(void) {}

std::string	Form::getName() const{
	return this->name;
}

bool		Form::getSign() const{
	return this->sign;
}

int			Form::getGradeToSign() const{
	return gradeToSign;
}

int			Form::getGradeToExecute() const{
	return gradeToExecute;
}

void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= gradeToSign)
		this->sign = true;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw() {
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &output, const Form &form) {
	output << form.getName() << " form is";
	if (form.getSign())
		output << " signed. This form requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	else
		output << " not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	return output;
}