#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <climits>
# include <exception>
# include <cstdlib>
# include <ctime>
# include <iterator>
# include <cctype>
# include "unistd.h"

class Span
{
	private:
		unsigned int 		N;
		std::vector<int> 	v;
		int 				min;

	public:
				Span(unsigned int n);
				Span(const Span &copy);
				~Span();
		Span	 &operator=(const Span &copy);
		void 	addNumber(int n);
		int 	shortestSpan();
		int 	longestSpan();
		void	fillRand();
		class 	FullException;
};

class Span::FullException : public std::exception
{
	public:
		virtual const char *what() const throw();
};

#endif