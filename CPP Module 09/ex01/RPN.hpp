#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{//Reverse Polish Notation
	private:
		std::stack<double> 	stack;
		std::string 		allowedValues;
		std::string 		input;
	public:
				RPN();
				RPN(const std::string & input);
				RPN(const RPN &copy);
				~RPN();
		RPN 	&operator=(const RPN &copy);
		void	checkInput(const std::string &input);
		void	fillStack(std::string input);
		void 	performOperation(char operation);
		void 	pushNumberOntoStack(std::string& input, size_t& i);
		void 	printResult(void) const;

		class 	EmptyStackException;
		class 	notAllowedValueException;
};

class RPN::EmptyStackException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class RPN::notAllowedValueException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif