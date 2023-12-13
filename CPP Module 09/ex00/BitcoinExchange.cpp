#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	std::string line;
	std::string date;
	std::string price;
	std::getline (file, line);
	while (std::getline (file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, '\n');
		this->setData(date, price);
	}
	boughtBTC = 0;
	file.close();
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	if (this != &rhs)
		this->data = rhs.data;
	return *this;
}

void	BitcoinExchange::setData(std::string date, std::string price) {
	int						Date;
	float 					Price;
	
	date = this->dashDeletedDate(date);
	std::stringstream(date) >> Date;
	Price = std::strtof(price.c_str(), 0);
	this->data.insert(std::pair<int, float>(Date, Price));
}

std::string	BitcoinExchange::dashDeletedDate(std::string date) {
	std::string dateWithoutDash;
	int i = 0;

	for (char c = date[i]; c != '\0'; c = date[++i]) {
		if (c != '-') {
			dateWithoutDash += c;
		}
	}
	return dateWithoutDash;
}

void	BitcoinExchange::compareData(std::string compareFile) {
	std::ifstream 	file(compareFile);
	if (!file.is_open())
		throw BitcoinExchange::fileNotFoundException();

	std::string 	line;
	std::string 	date;
	std::string 	dateWithoutDash;
	std::string 	spendature;
	int				dateInt;
	int				closestDate;
	float			spendatureFloat;
	float			btcPrice;

	std::getline (file, line);
	while (std::getline (file, line))
	{
		std::stringstream ss(line);
		std::getline(ss, date, ' ');
		ss.ignore(2);
		std::getline(ss, spendature, '\n');
		try {
			this->errorHandler(date, spendature);
		}
		catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			continue ;
		}
		dateWithoutDash = this->dashDeletedDate(date);
		std::stringstream(dateWithoutDash) >> dateInt;
		spendatureFloat = std::strtof(spendature.c_str(), 0);
		if (this->data.find(dateInt) == data.end()) {
			closestDate = data.lower_bound(dateInt)->first;
			btcPrice = this->data[closestDate];
		}
		else {
			btcPrice = this->data[dateInt];
		}
		this->boughtBTC += spendatureFloat * btcPrice;
		this->displayPurchaseInfo(date, spendature);
	}
	file.close();
}

void BitcoinExchange::displayPurchaseInfo(std::string date, std::string price) {
	std::cout << date << " => " << price << " = " << this->boughtBTC << std::endl;
	this->boughtBTC = 0;
}

bool BitcoinExchange::dateFormatChecker(std::string date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }

    int year = std::stoi(date.substr(0, 4));
    if (year < 2009 || year > 2023) {
        return false;
    }

    if ((date[5] < '0' || date[5] > '1') || (date[5] == '1' && date[6] > '2') 
        || (date[8] < '0' || date[8] > '3') || (date[8] == '3' && date[9] > '1')) {
        return false;
    }

    return true;
}

void	BitcoinExchange::errorHandler(std::string date, std::string price) {
	float 	priceFloat = std::strtof(price.c_str(), 0);
	long	priceInt = std::strtol(price.c_str(), 0, 0);
	int		i = 0;

	if (date.empty() || price.empty()) {
		throw BitcoinExchange::badInputException();
	}
	for (char c = date[i]; c != '\0'; c = date[++i]) {
		if (!std::isdigit(c) && c != '-') {
			throw BitcoinExchange::badInputException();
		}
	}
	i = 0;
	for (char c = price[i]; c != '\0'; c = price[++i]) {
		if (!std::isdigit(c) && c != '.' && c != '-') {
			throw BitcoinExchange::badInputException();
		}
	}
	if (!this->dateFormatChecker(date))
		throw BitcoinExchange::invalidDateException();
	if (priceFloat <= 0)
		throw BitcoinExchange::notAPositiveNumberException();
	if (priceInt > std::numeric_limits<int>::max())
		throw BitcoinExchange::numberTooLargeException();
}

const char* BitcoinExchange::badInputException::what() const throw() {
	return "Error : Bad input.";
}

const char* BitcoinExchange::notAPositiveNumberException::what() const throw() {
	return "Error : Not a positive number.";
}

const char* BitcoinExchange::numberTooLargeException::what() const throw() {
	return "Error : Number too large.";
}

const char* BitcoinExchange::invalidDateException::what() const throw() {
	return "Error : Invalid date.";
}

const char* BitcoinExchange::fileNotFoundException::what() const throw() {
	return "Error : File not found.";
}