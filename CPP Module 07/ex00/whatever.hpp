#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T tmp = a;
	a = b;
	b = tmp;
};

template <typename J>
J min(J a, J b)
{
	if (a < b)
		return (a);
	return (b);
};

template <typename T>
T max(T a, T b)
{
	if (a > b)
		return (a);
	return (b);
};

#endif