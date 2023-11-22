#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->arraySize = 0;
	this->data = NULL;
}

template <typename T>
Array<T>::Array(const unsigned int n){
	this->arraySize = n;
	this->data = new T[arraySize];
}

template <typename T>
Array<T>::Array(const Array &copy){
	*this = copy;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy){
	if (this != &copy)
	{
		if (this->data && this->arraySize && this->arraySize != 0 && this->data != NULL && this->data != 0 && this->data != nullptr)
		{
			std::cout << this->data << std::endl;
			std::cout << this->data[0] << std::endl;
			delete [] this->data;
		}
		this->arraySize = copy.arraySize;
		this->data = new T[arraySize];
		for (unsigned int i = 0; i < arraySize; i++)
			this->data[i] = copy.data[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(void){
	delete [] this->data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index){
	if (index >= this->arraySize)
		throw (InvalidInputException());
	return (this->data[index]);
}

template <typename T>
unsigned int Array<T>::size(void) const{
	return (this->arraySize);
}

template <typename T>
const char *Array<T>::InvalidInputException::what() const throw(){
	return ("Exception : Invalid input, index out of range.");
}

#endif