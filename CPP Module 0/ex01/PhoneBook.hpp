#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <ctime>

class PhoneBook {
private:
	Contact	contacts[8];
public:
	PhoneBook(void);
	std::string	getCurrentTimeAsString(void);
	std::string	initInterface(void);
	void		displayInterface(void);
	bool		getContactId(int id);
	void		addContact(void);
	void		displayContact(void);
};

extern PhoneBook phonebook;

#endif