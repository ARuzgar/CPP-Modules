#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &copy);
		~Intern();
		Intern &operator=(const Intern &copy);

		AForm *makeForm(std::string formName, std::string target);
		class FormNotFoundException;
};

	class Intern::FormNotFoundException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};

#endif