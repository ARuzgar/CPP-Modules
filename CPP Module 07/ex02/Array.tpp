#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->arraySize = 0;
	this->n = new T[arraySize];
}

template <typename T>
Array<T>::Array(const unsigned int n){
}

template <typename T>
Array<T>::Array(const Array &copy){}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy){}

template <typename T>
Array<T>::~Array(void){}


#endif