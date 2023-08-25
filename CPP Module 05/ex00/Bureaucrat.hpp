#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

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

		void		incrementGrade(void);
		void		decrementGrade(void);
		int			getGrade(void) const;
		std::string getName(void) const;

		class GradeTooHighException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception{
			public :
				virtual const char *what() const throw();
		};
};

	std::ostream &operator<<(std::ostream &output, Bureaucrat &bboy);
#endif