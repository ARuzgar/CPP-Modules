#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **av) : av(av), timeVec(0), timeLst(0), size(ac - 1) {
	if (ac < 3)
		throw notEnoughArgsException();
	fillTheContainers();
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
	std::cout << "Time to process a range of " << size << " elements with std::vector: " << timeVec << " ms" << std::endl;
	std::cout << "Time to process a range of " << size << " elements with std::list: " << timeLst << " ms" << std::endl;
}

void PmergeMe::mergeVec() {
	int* temp = new int[size];
    mergeVecHelper(temp, 0, size - 1);
    delete[] temp;
}

void PmergeMe::mergeVecHelper(int* temp, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeVecHelper(temp, left, mid);
        mergeVecHelper(temp, mid + 1, right);

        // Merge the sorted halves
        int i = left;
        int j = mid + 1;
        int k = 0;

        while (i <= mid && j <= right) {
            if (vec[i] < vec[j]) {
                temp[k++] = vec[i++];
            } else {
                temp[k++] = vec[j++];
            }
        }

        while (i <= mid) {
            temp[k++] = vec[i++];
        }

        while (j <= right) {
            temp[k++] = vec[j++];
        }

        // Copy the merged elements back to the original vector
        for (i = 0; i < k; ++i) {
            vec[left + i] = temp[i];
        }
    }
}

void PmergeMe::insertVec() {
	for (int i = 1; i < size; ++i) {
        int key = vec[i];
        int j = i - 1;

        // Move elements greater than key to one position ahead of their current position
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            --j;
        }
        vec[j + 1] = key;
    }
}

void PmergeMe::mergeInsertSortVec() {
	if (size > 10) {  // Use Merge Sort for larger lists
        mergeVec();
    } else {  // Use Insertion Sort for smaller lists
        insertVec();
    }
}

void PmergeMe::mergeLst() {
    // Implement Merge Sort for std::list
    if (lst.size() <= 1) return;

    std::list<int> left, right;

    int middle = lst.size() / 2;
    int count = 0;

    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        if (count < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        ++count;
    }

    // Recursively sort sublists
    mergeLstHelper(left);
    mergeLstHelper(right);

    // Merge the sorted sublists
    lst.clear();
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            lst.push_back(left.front());
            left.pop_front();
        } else {
            lst.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        lst.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        lst.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::mergeLstHelper(std::list<int> &sublist) {
    if (sublist.size() <= 1) return;

    std::list<int> left, right;

    int middle = sublist.size() / 2;
    int count = 0;

    for (std::list<int>::iterator it = sublist.begin(); it != sublist.end(); ++it) {
        if (count < middle) {
            left.push_back(*it);
        } else {
            right.push_back(*it);
        }
        ++count;
    }

    // Recursively sort sublists
    mergeLstHelper(left);
    mergeLstHelper(right);

    // Merge the sorted sublists
    sublist.clear();
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            sublist.push_back(left.front());
            left.pop_front();
        } else {
            sublist.push_back(right.front());
            right.pop_front();
        }
    }

    while (!left.empty()) {
        sublist.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        sublist.push_back(right.front());
        right.pop_front();
    }
}

void PmergeMe::insertLst() {
    // Implement Insertion Sort for std::list
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::list<int>::iterator current = it;
        std::list<int>::iterator prev = it;
        --prev;

        while (current != lst.begin() && *current < *prev) {
            std::swap(*current, *prev);
            --current;
            --prev;
        }
    }
}

void PmergeMe::mergeInsertSortLst() {
    if (size > 10) { 
        mergeLst();
    } else {
        insertLst();
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

int PmergeMe::getSize() const {
	return (size);
}

const char * PmergeMe::notIntException::what() const throw() {
	return ("The sequence contains non-integral values.");
}

const char * PmergeMe::notEnoughArgsException::what() const throw() {
	return ("Not enough arguments.");
}