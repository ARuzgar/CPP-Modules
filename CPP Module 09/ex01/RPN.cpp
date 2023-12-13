#include "RPN.hpp"

RPN::RPN() {}

/**
 * @brief Constructs an RPN object with the given input.
 * 
 * This constructor initializes an RPN object with the provided input string.
 * The input string should contain valid RPN (Reverse Polish Notation) expressions.
 *  
 * RPN is a mathematical notation in which every operator follows all of its operands.
 * In RPN, instead of using parentheses to indicate the order of operations, the order is determined by the position of the operators.
 * 
 * The allowed values in the input string are:
 * - Digits: 0-9
 * - Arithmetic operators: +, -, *, /
 * 
 * @param input The input string for the RPN calculation. 
 * */

RPN::RPN(const std::string &input) {
	allowedValues = "0123456789.+-*/";
	try{
		checkInput(input);
		fillStack(input);
		printResult();
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		return ;
	}
}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN::~RPN() {}

RPN &	RPN::operator=(const RPN &copy) {
	if (this != &copy) {
		this->stack = copy.stack;
	}
	return (*this);
}

/**
 * @brief Checks the validity of the input string for the RPN calculator.
 * 
 * This function checks if the input string is empty and if it contains only allowed values.
 * If the input string is empty, it throws an EmptyStackException.
 * If the input string contains any value that is not allowed, it throws a notAllowedValueException.
 * 
 * @param input The input string to be checked.
 * @throws EmptyStackException If the input string is empty.
 * @throws notAllowedValueException If the input string contains any value that is not allowed.
 */
void	RPN::checkInput(const std::string &input) {
	std::cout << "input: " << input << std::endl;
	if (input.length() == 0)
		throw EmptyStackException();
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == ' ')
			continue ;
		if (allowedValues.find(input[i]) == std::string::npos)
			throw notAllowedValueException();
	}
}

/**
 * Pushes a number onto the stack.
 * 
 * This function reads a sequence of digits from the input string starting at the given index,
 * converts it to an integer, and pushes it onto the stack.
 * 
 * @param input The input string.
 * @param i The index to start reading from.
 */
void RPN::pushNumberOntoStack(std::string& input, size_t& i) {
    int number = 0;
    while(i < input.length() && input[i] >= '0' && input[i] <= '9') {
        number = number * 10 + (input[i] - '0');
        i++;
    }
    stack.push(number);
}

/**
 * Performs the specified operation on the top two elements of the stack.
 * 
 * This function takes an operation as input ('+', '-', '*', '/') and performs the operation on the top two elements of the stack.
 * It throws an EmptyStackException if the stack contains less than 2 elements.
 * 
 * @param operation The operation to be performed ('+', '-', '*', '/')
 * @throws EmptyStackException if the stack contains less than 2 elements
 */
void RPN::performOperation(char operation) {
	if (stack.size() < 2)
		throw EmptyStackException();

	// Get the top two elements from the stack
	double a = stack.top();
	stack.pop();
	double b = stack.top();
	stack.pop();

	// Perform the specified operation and push the result back onto the stack
	if (operation == '+')
		stack.push(b + a);
	else if (operation == '-')
		stack.push(b - a);
	else if (operation == '*')
		stack.push(b * a);
	else if (operation == '/')
		stack.push(b / a);
}

/**
 * Fills the stack with numbers and performs operations based on the input string.
 * 
 * This function iterates through the characters of the input string and performs the following actions:
 * - If the character is a space, it is skipped.
 * - If the character is a digit (0-9), it calls the `pushNumberOntoStack` function to convert the sequence of digits to an integer and push it onto the stack.
 * - If the character is an operator (+, -, *, /), it calls the `performOperation` function to perform the specified operation on the top two elements of the stack.
 * 
 * @param input The input string containing numbers and operators.
 */
void RPN::fillStack(std::string input) {
	for (size_t i = 0; i < input.length(); i++) {
		if (input[i] == ' ')
			continue ;
		if (input[i] >= '0' && input[i] <= '9') {
			pushNumberOntoStack(input, i);
		}
		else if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
			performOperation(input[i]);
		}
	}
}

/**
 * Prints the result of the RPN calculation.
 * Throws an EmptyStackException if the stack is not empty.
 */
void RPN::printResult(void) const {
	if (stack.size() != 1)
		throw EmptyStackException();
	std::cout << stack.top() << std::endl;
}

const char* RPN::EmptyStackException::what() const throw() {
	return ("Error: Stack is empty");
}

const char* RPN::notAllowedValueException::what() const throw() {
	return ("Error: Not allowed value");
}
