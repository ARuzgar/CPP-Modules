#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	std::ifstream file("data.csv");
	if (!file.is_open())
		throw BitcoinExchange::fileNotFoundException();
	std::string line, date, price;
	std::getline (file, line);
	while (std::getline (file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, '\n');
		setData(date, price);
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

void	BitcoinExchange::setData(std::string const &date, std::string const &price) {
	int						intDate;
	float 					floatPrice;
	std::string				dateWithoutDash;
	
	dateWithoutDash = dashDeletedDate(date);
	std::stringstream(dateWithoutDash) >> intDate;
	floatPrice = std::strtof(price.c_str(), 0);
	data.insert(std::pair<int, float>(intDate, floatPrice));
}

std::string	BitcoinExchange::dashDeletedDate(std::string const &date) const {
	std::string dateWithoutDash;
	int i = 0;

	for (char c = date[i]; c != '\0'; c = date[++i]) {
		if (c != '-') {
			dateWithoutDash += c;
		}
	}
	return dateWithoutDash;
}

void BitcoinExchange::parseLine(const std::string& line, std::string& date, std::string& spendature) {
    std::stringstream ss(line);
    std::getline(ss, date, ' ');
    ss.ignore(2);
    std::getline(ss, spendature, '\n');
}

int BitcoinExchange::convertDateToInt(std::string const &date) const {
    std::string dateWithoutDash = dashDeletedDate(date);
    int dateInt;
    std::stringstream(dateWithoutDash) >> dateInt;
    return dateInt;
}

float BitcoinExchange::convertSpendatureToFloat(std::string const &spendature) const {
    return std::strtof(spendature.c_str(), 0);
}

float BitcoinExchange::getBitcoinPrice(int dateInt) const {
    float btcPrice;
    std::map<int, float>::const_iterator it;

    if (data.find(dateInt) == data.end()) {
        it = data.upper_bound(dateInt);
        if (it == data.begin()) {
            btcPrice = it->second;
        } 
		else {
            --it;
            btcPrice = it->second;
        }
    } 
	else {
        btcPrice = data.at(dateInt);
    }
    return btcPrice;
}

void BitcoinExchange::updateBoughtBTC(float const & spendatureFloat, float const &btcPrice) {
    boughtBTC += spendatureFloat * btcPrice;
}

void BitcoinExchange::resetBoughtBTC() {
    boughtBTC = 0;
}

void BitcoinExchange::processData(const std::string& date, const std::string& spendature) {
    int dateInt = convertDateToInt(date);
    float spendatureFloat = convertSpendatureToFloat(spendature);
    float btcPrice = getBitcoinPrice(dateInt);
    updateBoughtBTC(spendatureFloat, btcPrice);
    displayPurchaseInfo(date, spendature);
    resetBoughtBTC();
}

void BitcoinExchange::compareData(std::string const &compareFile) {
    std::ifstream file(compareFile);
    if (!file.is_open())
        throw BitcoinExchange::fileNotFoundException();

    std::string line, date, spendature;

    std::getline(file, line);
    while (std::getline(file, line)) {
        parseLine(line, date, spendature);
        try {
            errorHandler(date, spendature);
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
            continue;
        }
        processData(date, spendature);
    }
    file.close();
}

void BitcoinExchange::displayPurchaseInfo(std::string const &date, std::string const & price) const {
	std::cout << date << " => " << price << " = " << boughtBTC << std::endl;
}

bool BitcoinExchange::dateFormatChecker(std::string const &date) const {
    if (date.length() != DATE_LENGTH || date[FIRST_DASH_POSITION] != '-' || date[SECOND_DASH_POSITION] != '-') {
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

void	BitcoinExchange::errorHandler(std::string const &date, std::string const &price) const {
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
	if (!dateFormatChecker(date))
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