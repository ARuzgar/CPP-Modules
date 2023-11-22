#ifndef ARRAY_H
#define ARRAY_H

#include <exception>

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
};

#include "Array.tpp"

#endif
