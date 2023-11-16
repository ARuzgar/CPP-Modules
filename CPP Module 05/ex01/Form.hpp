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
// Orthodox Cannonical Form Basics
		Form(void); //Constructor
		Form(const std::string &name, int gradeToSign, int gradeToExecute); //Constructor Func. Overload
		Form(Form const &copy); //Copy Constructor
		Form &operator=(Form const &otherForm); //Operator Overload
		~Form(void); //Deconstructor

// Getter's
		std::string getName() const;
		bool		getSign() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;
// Setter's
		void		beSigned(Bureaucrat &bureaucrat);
// Exception Handler's
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