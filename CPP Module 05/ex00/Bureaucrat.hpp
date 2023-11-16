#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <exception>

class Bureaucrat
{
	private:
		std::string name;
		int			grade;

	public:
//Orthodox Cannonical Form Basics

		Bureaucrat(void); //Constructor
		Bureaucrat(const std::string &name, int grade); //Constructor Func. Overload
		Bureaucrat(Bureaucrat const &copy); //Copy Constructor(also kinda a Func. overload to Constructor)
		Bureaucrat &operator=(Bureaucrat const &otherBureaucrat); //Operator Overload(Assign operator, usually for deep copy)
		~Bureaucrat(void); //Deconstructor

// Grade modification methods
		void		incrementGrade();
		void		decrementGrade();

// Getter's
		int			getGrade() const;
		std::string getName() const;
		
// Exception Handler's
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