#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <sstream>

class Brain
{
	private:
		std::string Ideas[100];
	public:
		Brain(void);
		Brain(Brain const &copy);
		Brain &operator=(Brain const &otherBrain);
		~Brain(void);
	
		std::string *getIdeas(void);
		std::string getIdea(int idea) const;
};

#endif