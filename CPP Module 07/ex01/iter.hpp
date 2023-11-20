#ifndef ITER_HPP
# define ITER_HPP

template <typename TP, typename TF, typename TA >
void iter(TP *array, size_t length, TF (*f)(TA &))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
};

#endif