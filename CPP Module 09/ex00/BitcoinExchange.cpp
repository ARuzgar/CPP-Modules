#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	readDataFromFile("data.csv");
	boughtBTC = 0;
}

/**
 * Reads data from a file and sets the data in the BitcoinExchange object.
 * 
 * @param filename The name of the file to read data from.
 * @throws BitcoinExchange::fileNotFoundException if the file cannot be opened.
 */
void BitcoinExchange::readDataFromFile(const std::string& filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw BitcoinExchange::fileNotFoundException();
	std::string line, date, price;
	std::getline(file, line);
	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, price, '\n');
		setData(date, price);
	}
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

/**
 * @brief Sets the data for the BitcoinExchange object.
 * 
 * This function takes a date and price as input and stores them in the data member of the BitcoinExchange object.
 * The date is converted to an integer by removing the dashes, and the price is converted to a float using std::strtof.
 * The converted values are then inserted into the data map using std::pair<int, float>.
 * 
 * @param date The date in string format.
 * @param price The price in string format.
 */
void	BitcoinExchange::setData(std::string const &date, std::string const &price) {
	int						intDate;
	float 					floatPrice;
	std::string				dateWithoutDash;
	
	dateWithoutDash = dashDeletedDate(date);
	std::stringstream(dateWithoutDash) >> intDate;
	floatPrice = std::strtof(price.c_str(), 0);
	data.insert(std::pair<int, float>(intDate, floatPrice));
}

/**
 * @brief Removes dashes from a given date string.
 * 
 * This function takes a date string as input and removes all dashes ('-') from it.
 * The modified date string without dashes is then returned.
 * 
 * @param date The date string from which dashes are to be removed.
 * @return std::string The modified date string without dashes.
 */
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

/**
 * @brief Parses a line of input and extracts the date and spendature.
 * 
 * This function takes a line of input as a parameter and extracts the date and spendature
 * from it. The date is stored in the 'date' parameter and the spendature is stored in the
 * 'spendature' parameter.
 * 
 * @param line The line of input to parse.
 * @param date The variable to store the extracted date.
 * @param spendature The variable to store the extracted spendature.
 */
void BitcoinExchange::parseLine(const std::string& line, std::string& date, std::string& spendature) {
    std::stringstream ss(line);
    std::getline(ss, date, ' ');
    ss.ignore(2);
    std::getline(ss, spendature, '\n');
}

/**
 * Converts a date string to an integer representation.
 * 
 * @param date The date string to be converted.
 * @return The integer representation of the date.
 */
int BitcoinExchange::convertDateToInt(std::string const &date) const {
    std::string dateWithoutDash = dashDeletedDate(date);
    int dateInt;
    std::stringstream(dateWithoutDash) >> dateInt;
    return dateInt;
}

float BitcoinExchange::convertSpendatureToFloat(std::string const &spendature) const {
    return std::strtof(spendature.c_str(), 0);
}

/**
 * @brief Retrieves the price of Bitcoin for a given date.
 * If the exact date is not found in the data, it returns the closest (older) available price.
 *
 * @param dateInt The date for which to retrieve the Bitcoin price.
 * @return The price of Bitcoin for the given date.
 */
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

/**
 * @brief Processes the data for a given date and spendature.
 * 
 * This function converts the date to an integer, the spendature to a float,
 * retrieves the Bitcoin price for the given date, updates the bought BTC,
 * displays the purchase information, and resets the bought BTC.
 * 
 * @param date The date in string format.
 * @param spendature The spendature in string format.
 */
void BitcoinExchange::processData(const std::string& date, const std::string& spendature) {
    int dateInt = convertDateToInt(date);
    float spendatureFloat = convertSpendatureToFloat(spendature);
    float btcPrice = getBitcoinPrice(dateInt);
    updateBoughtBTC(spendatureFloat, btcPrice);
    displayPurchaseInfo(date, spendature);
    resetBoughtBTC();
}

/**
 * @brief Compares the data in the given file with the data in the BitcoinExchange object.
 * 
 * This function reads the data from the given file and compares it with the data stored in the BitcoinExchange object.
 * It parses each line of the file, handles any errors that occur, and processes the valid data.
 * 
 * @param compareFile The path of the file to compare the data with.
 * @throws BitcoinExchange::fileNotFoundException if the file cannot be opened.
 */
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

/**
 * @brief Checks if the given date string has a valid format.
 * The date format should be "YYYY-MM-DD".
 * 
 * @param date The date string to be checked.
 * @return True if the date format is valid, false otherwise.
 */
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

/**
 * @brief Handles errors in the BitcoinExchange class.
 * 
 * This function checks if the given date and price are valid and throws exceptions if they are not.
 * 
 * @param date The date string to be checked.
 * @param price The price string to be checked.
 * @throws BitcoinExchange::badInputException if either the date or price is empty.
 * @throws BitcoinExchange::badInputException if the date contains non-digit or non-hyphen characters.
 * @throws BitcoinExchange::badInputException if the price contains non-digit, non-period, or non-hyphen characters.
 * @throws BitcoinExchange::invalidDateException if the date is not in the correct format.
 * @throws BitcoinExchange::notAPositiveNumberException if the price is less than or equal to zero.
 * @throws BitcoinExchange::numberTooLargeException if the price is larger than the maximum value of an int.
 */
void	BitcoinExchange::errorHandler(std::string const &date, std::string const &price) const {
	float priceFloat = std::strtof(price.c_str(), 0);
	long priceInt = std::strtol(price.c_str(), 0, 0);
	int i = 0;
	std::string wrongDate = date;

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
	{
		BitcoinExchange::invalidDateException invalidDate;
		invalidDate.setDate(wrongDate);
		throw invalidDate;
	}
	if (priceFloat <= 0)
		throw BitcoinExchange::notAPositiveNumberException();
	if (priceInt > std::numeric_limits<int>::max())
		throw BitcoinExchange::numberTooLargeException();
}

/**
 * @brief Sets the date for the invalidDateException object.
 * 
 * This function sets the date for the invalidDateException object and appends an error message to it.
 * 
 * @param date The invalid date.
 */
void BitcoinExchange::invalidDateException::setDate(std::string &date) {
	this->date = "Error : Invalid date => " + date;
}

BitcoinExchange::invalidDateException::~invalidDateException() throw() {
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
	return (date.c_str());
}

const char* BitcoinExchange::fileNotFoundException::what() const throw() {
	return "Error : File not found.";
}