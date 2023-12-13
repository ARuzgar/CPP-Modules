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
# include <exception>
# include <map>

const int DATE_LENGTH = 10;
const int FIRST_DASH_POSITION = 4;
const int SECOND_DASH_POSITION = 7;

class BitcoinExchange
{
	private:
		std::map<int, float> 	data;
		float 					boughtBTC;
		std::string				wrongDate;
	public:
								BitcoinExchange();
								BitcoinExchange(BitcoinExchange const & src);
								~BitcoinExchange();
		BitcoinExchange 		&operator=(BitcoinExchange const & rhs);

		void					setData(std::string const &date, std::string const &price);
		std::string				dashDeletedDate(std::string const &date) const;
		void 					parseLine(const std::string& line, std::string& date, std::string& spendature);
		void 					processData(const std::string& date, const std::string& spendature);
		void					compareData(std::string const &compareFile);
		void 					displayPurchaseInfo(std::string const &date, std::string const & price) const;
		bool 					dateFormatChecker(std::string const &date) const;
		void					errorHandler(std::string const &date, std::string const &price) const;
		int 					convertDateToInt(std::string const &date) const;
		float 					convertSpendatureToFloat(std::string const &spendature) const;
		float 					getBitcoinPrice(int dateInt) const;
		void 					updateBoughtBTC(float const &spendatureFloat, float const &btcPrice);
		void 					resetBoughtBTC();
		void 					readDataFromFile(const std::string& filename);

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
	private:
		std::string date;
	public:
		void	setDate(std::string &date);
		~invalidDateException() throw();
		virtual const char* what() const throw();
};

class BitcoinExchange::fileNotFoundException : public std::exception
{
	public:
		virtual const char* what() const throw();
};

#endif