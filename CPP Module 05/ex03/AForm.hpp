#ifndef AAFORM_HPP
# define AAFORM_HPP

# include <iostream>
# include <exception>
# include <string>
# include <fstream>
# include <sstream>
# include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string 		name;
		const int				gradeToSign;
		const int				gradeToExecute;
		bool			sign;

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
		virtual void 	execute(Bureaucrat const & executor) const = 0;
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