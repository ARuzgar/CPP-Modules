# include "Form.hpp"

Form::Form(void) {
	this->name = "Form";
	this->sign = false;
	this->gradeToSign = 150;
	this->gradeToExecute = 150;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) {
	this->name = name;
	this->sign = false;
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	else if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	this->gradeToSign = gradeToSign;
	this->gradeToExecute = gradeToExecute;
}

Form::Form(Form const &copy) {
	*this = copy;
}

Form &	Form::operator=(Form const &otherForm) {
	this->name = otherForm.name;
	this->sign = otherForm.sign;
	this->gradeToSign = otherForm.gradeToSign;
	this->gradeToExecute = otherForm.gradeToExecute;
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
	return this->gradeToSign;
}

int			Form::getGradeToExecute() const{
	return this->gradeToExecute;
}

void		Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() <= this->gradeToSign)
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
	output << form.getName() << " form is ";
	if (form.getSign())
		output << " signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	else
		output << " not signed and requires a grade " << form.getGradeToSign() << " to sign and a grade " << form.getGradeToExecute() << " to execute.";
	return output;
}