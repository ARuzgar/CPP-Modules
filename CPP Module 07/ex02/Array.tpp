#ifndef ARRAY_TPP
# define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array(void)
{
	this->arraySize = 0;
	this->data = nullptr;
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
Array<T> &Array<T>::operator=(const Array &copy) {
    if (this != &copy) {
		if (data != nullptr && arraySize > 0)
	        delete[] data; // Deallocate current memory
        arraySize = copy.arraySize;
        data = new T[arraySize]; // Allocate new memory
        for (unsigned int i = 0; i < arraySize; ++i)
            data[i] = copy.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array(void) {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
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