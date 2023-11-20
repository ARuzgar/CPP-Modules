#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <exception>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string name;
		bool		sign;
		int			gradeToSign;
		int			gradeToExecute;

	public:
		Form(void);
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(Form const &copy);
		Form &operator=(Form const &otherForm);
		~Form(void);

		std::string getName() const;
		bool		getSign() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
		void		beSigned(Bureaucrat &bureaucrat);
		class GradeTooHighException;
		class GradeTooLowException;
};

class Form::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class Form::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream &output, const Form &form);

#endif