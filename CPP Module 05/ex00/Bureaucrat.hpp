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

		void		incrementGrade();
		void		decrementGrade();
		int			getGrade() const;
		std::string getName() const;
};

#endif