#ifndef AAFORM_HPP
# define AAFORM_HPP

# include <iostream>
# include <exception>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string 	name;
		bool			sign;
		int				gradeToSign;
		int				gradeToExecute;

	public:
						AForm(void);
						AForm(const std::string &name, int gradeToSign, int gradeToExecute);
						AForm(AForm const &copy);
		virtual AForm 	&operator=(AForm const &otherAForm);
		virtual 		~AForm(void);

		bool			getSign() const;
		int				getGradeToSign() const;
		int				getGradeToExecute() const;
		std::string 	getName() const;
		

		virtual void	action() const = 0;
		void 			execute(Bureaucrat const & executor) const;
		void			beSigned(Bureaucrat &bureaucrat);
		class 			GradeTooHighException;
		class 			GradeTooLowException;
		class			FormNotSignedException;
};

class AForm::GradeTooHighException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class AForm::GradeTooLowException : public std::exception {
	public:
		virtual const char* what() const throw();
};

class AForm::FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw();
};

std::ostream &operator<<(std::ostream &output, const AForm &Aform);

#endif