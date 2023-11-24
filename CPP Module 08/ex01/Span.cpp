#include "Span.hpp"

Span::Span(unsigned int n) {
	this->N = n;
	this->v.reserve(n);
}

Span::Span(const Span &copy) {
	*this = copy;
}


Span & Span::operator=(const Span &copy) {
	if (this != &copy) {
		this->N = copy.N;
		this->v = copy.v;
		this->min = copy.min;
	}
	return *this;
}

Span::~Span() {}
void Span::addNumber(int n) {
	this->v.push_back(n);
}

int Span::shortestSpan() {
	this->min = INT_MAX;
	if (this->v.size() < 2)
		throw Span::FullException();
	std::sort(this->v.begin(), this->v.end());
	for (std::vector<int>::iterator it = this->v.begin(); it != this->v.end() - 1; it++) {
		if (*(it + 1) - *it < min)
			this->min = *(it + 1) - *it;
	}
	return this->min;
}

int Span::longestSpan() {
	if (this->v.size() < 2)
		throw Span::FullException();
	std::sort(this->v.begin(), this->v.end());
	return (*(this->v.end() - 1) - *(this->v.begin()));
}

void Span::fillRand(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	srand(time(NULL));
	for (std::vector<int>::iterator it = begin; it != end; it++) {
		*it = rand();
	}
}

const char *Span::FullException::what() const throw() {
	return "Span is full";
}
