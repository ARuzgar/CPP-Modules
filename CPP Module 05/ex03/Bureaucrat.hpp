#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string name;
		int			grade;
	public:

					Bureaucrat(void);
					Bureaucrat(const std::string &name, int grade);
					Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &otherBureaucrat);
					~Bureaucrat(void);

		void		incrementGrade();
		void		decrementGrade();
		int			getGrade() const;
		std::string getName() const;
		
		void 		executeForm(AForm const & form);
		void 		signForm(AForm &form);
		class 		GradeTooHighException;
		class 		GradeTooLowException;
};

class Bureaucrat::GradeTooHighException : public std::exception {
	public:
    	virtual const char* what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception {
	public:
    	virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);

#endif