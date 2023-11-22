#ifndef ARRAY_H
#define ARRAY_H

#include <exception>
#include <iostream>

template <typename T>
class Array
{
	private:
		T* data;
		unsigned int arraySize;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& other);
		Array<T>& operator=(const Array<T>& other);
		~Array();
		T& operator[](unsigned int index);
		unsigned int size() const;
		class InvalidInputException;
};

template <typename T>
class Array<T>::InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
};

#include "Array.tpp"

#endif
