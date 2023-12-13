#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <cstdlib>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <iterator>
# include <map>
# include <exception>

class BitcoinExchange
{
	private:
		std::map<int, float> 	data;
		float 					boughtBTC;
	public:
								BitcoinExchange();
								BitcoinExchange(BitcoinExchange const & src);
								~BitcoinExchange();
		BitcoinExchange 		&operator=(BitcoinExchange const & rhs);
		void					setData(std::string date, std::string price);
		std::string				dashDeletedDate(std::string date);
		void 					displayPurchaseInfo(std::string date, std::string price);
		bool 					dateFormatChecker(std::string date);
		void					errorHandler(std::string date, std::string price);
		void					compareData(std::string compareFile);

		class					badInputException;
		class					notAPositiveNumberException;
		class					numberTooLargeException;
		class					invalidDateException;
		class					fileNotFoundException;
};

class BitcoinExchange::badInputException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::notAPositiveNumberException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::numberTooLargeException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::invalidDateException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

class BitcoinExchange::fileNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif