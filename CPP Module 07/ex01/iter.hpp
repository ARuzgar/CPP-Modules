#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <unistd.h>
# include <functional>

//color
# define schwarz "\033[30m"
# define rot "\033[31m"
# define gruen "\033[32m"
# define gelb "\033[33m"
# define blau "\033[34m"
# define magenta "\033[35m"
# define scratch "\033[36m"
# define scrclean 	"\033[2J\033[1;1H"
# define reset "\033[0m"

template <typename TP, typename TF>
void iter(TP *array, size_t length, TF f)
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
};


#endif