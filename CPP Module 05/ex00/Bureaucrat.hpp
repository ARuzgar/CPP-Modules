#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
	private:
		std::string 	name;
		unsigned int	grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name, unsigned int grade);
		Bureaucrat(Bureaucrat const &copy);
		Bureaucrat &operator=(Bureaucrat const &otherBureaucrat);
		Bureaucrat &operator<<(Bureaucrat const &rhs);
		~Bureaucrat(void);

		void gradeTooHighException();
		void gradeTooLowException();
		std::string getName();
		int getGrade();

};

#endif