#ifndef CONTACT_HPP
# define CONTACT_HPP
#include <iostream>

class	Contact {
private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
public:
	Contact();
	void		setFirstName(void);
	void		setLastName(void);
	void		setNickname(void);
	void		setPhoneNumber(void);
	void		setDarkestSecret(void);
	void		setZeroIt(void);
	std::string	getFirstName(char);
	std::string	getLastName(char);
	std::string	getNickname(char);
	std::string	getPhoneNumber(char);
	std::string	getDarkestSecret(char);
};

#endif