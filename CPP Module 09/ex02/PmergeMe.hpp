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
		int					left;
		int					right;
		int					mid;

	public:
						PmergeMe(int ac, char **av);
						PmergeMe(PmergeMe const & src);
						~PmergeMe(void);
		PmergeMe	 &	operator=(PmergeMe const & rhs);

		void			fillTheContainers();
		void			containerTimeComparison(void);
		void			printContainerComparison();
		void			mergeVec();
		void			insertVec();
		void			mergeInsertSortVec(void);
		void			insertLst();
		void			mergeLst();
		void			mergeInsertSortLst(void);
		void			checkDuplicates();
		void			checkNonInts();

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