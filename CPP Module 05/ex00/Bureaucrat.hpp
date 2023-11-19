#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>
# include "./Form.hpp"

//colours
# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define MAGENTA	"\033[35m"
# define CYAN		"\033[36m"
# define WHITE		"\033[37m"
# define scrclean 	"\033[2J\033[1;1H"

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
		
		class GradeTooHighException;
		class GradeTooLowException;
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