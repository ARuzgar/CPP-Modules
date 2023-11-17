#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string target;
	public:
								RobotomyRequestForm(void);
								RobotomyRequestForm(const std::string &target);
								RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm 	&operator=(RobotomyRequestForm const &otherRobotomyRequestForm);
								~RobotomyRequestForm(void);

		void					action() const;
		std::string 			getTarget() const;
};

#endif