#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) : timeVec(0), timeLst(0), size(ac - 1), left(0), right(ac - 1), mid(0), av(av){
	if (ac < 2)
		throw notEnoughArgsException();
	fillTheContainers();
	checkDuplicates();
	checkNonInts();
	containerTimeComparison();
}

PmergeMe::PmergeMe(PmergeMe const & src) {
	*this = src;
}

PmergeMe::~PmergeMe(void) {
}

PmergeMe & PmergeMe::operator=(PmergeMe const & rhs) {
	if (this != &rhs) {
		this->vec = rhs.vec;
		this->lst = rhs.lst;
	}
	return (*this);
}

void PmergeMe::fillTheContainers() {
	for (int i = 0; i < size; i++) {
		vec.push_back(atoi(av[i]));
		lst.push_back(atoi(av[i]));
	}
}

void PmergeMe::containerTimeComparison(void) {
	std::time_t start = std::clock();
	mergeInsertSortVec();
	std::time_t end = std::clock();
	timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC;
	std::time_t start2 = std::clock();
	mergeInsertSortLst();
	std::time_t end2 = std::clock();
	timeLst = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC;
}

void PmergeMe::printContainerComparison() {
	std::cout << "Before: ";
	for (int i = 0; i < size; i++)
		std::cout << av[i] << " ";
	std::cout << std::endl;
	containerTimeComparison();
	std::cout << "After: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::vector: " << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::list: " << timeLst << " us" << std::endl;
}

void PmergeMe::mergeVec() {

}

void PmergeMe::insertVec() {

}

void PmergeMe::mergeInsertSortVec() {

}

void PmergeMe::mergeLst() {

}

void PmergeMe::insertLst() {

}

void PmergeMe::mergeInsertSortLst() {
	if (
}

void PmergeMe::checkDuplicates() {
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	for (; it != ite; it++) {
		if (std::count(it, ite, *it) > 1)
			throw duplicateException();
	}
}

void PmergeMe::checkNonInts() {
	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();
	for (; it != ite; it++) {
		if (*it != static_cast<int>(*it))
			throw notIntException();
	}
}


const char * PmergeMe::duplicateException::what() const throw() {
	return ("The sequence contains duplicate values.");
}

const char * PmergeMe::notIntException::what() const throw() {
	return ("The sequence contains non-integral values.");
}

const char * PmergeMe::notEnoughArgsException::what() const throw() {
	return ("Not enough arguments.");
}