#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <exception>
# include <iterator>

class NotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw()
		{
			return ("Value not found");
		}
};

template<typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator cont = std::find(container.begin(), container.end(), value);
	if (cont == container.end())
		throw NotFoundException();
	return cont;
}

#endif