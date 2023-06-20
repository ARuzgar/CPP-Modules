#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
	public:
		Brain(void);
		Brain(Brain const &other);
		Brain &operator=(Brain const &rhs);
		~Brain(void);
		std::string *getIdeas();
		std::string getIdea(int i) const;

	private:
		std::string Ideas[100];
};

#endif