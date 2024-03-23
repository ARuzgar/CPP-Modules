#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <vector>
# include <list>
# include <exception>
# include <iterator>
# include <ctime>

class PmergeMe {
	private:
		std::vector<int>	vec;
		std::list<int>		lst;
		char				**av;
		double				timeVec;
		double				timeLst;
		int					size;

	public:
						PmergeMe(int ac, char **av);
						PmergeMe(PmergeMe const & src);
						~PmergeMe(void);
		PmergeMe	 &	operator=(PmergeMe const & rhs);

		void			fillTheContainers();
		void			containerTimeComparison(void);
		void			printContainerComparison();

		void			mergeVec();
		void 			mergeVecHelper(int* temp, int left, int right);
		void			insertVec();
		void			mergeInsertSortVec(void);

		void			mergeLst();
		void			mergeLstHelper(std::list<int> &sublist);
		void			insertLst();
		void			mergeInsertSortLst(void);

		void			checkDuplicates();
		void			checkNonInts();

		int				getSize() const;

		class duplicateException;
		class notIntException;
		class notEnoughArgsException;
};

class PmergeMe::duplicateException : public std::exception {
	virtual const char* what() const throw();
};

class PmergeMe::notIntException : public std::exception {
	virtual const char* what() const throw();
};

class PmergeMe::notEnoughArgsException : public std::exception {
	virtual const char* what() const throw();
};

#endif