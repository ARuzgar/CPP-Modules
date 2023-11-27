#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void){

}

std::string PhoneBook::getCurrentTimeAsString(void)
{
	std::time_t currentTime = std::time(nullptr);
	std::tm* timeInfo = std::localtime(&currentTime);

	std::ostringstream oss;
	oss << std::put_time(timeInfo, "%R");

	return oss.str();
}

void PhoneBook::displayInterface(void)
{
	std::cout << "\033[1;35m|" << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	for (int i = 0; i <= 7; i++)
	{
		std::cout << "\033[1;35m|" << std::setw(10) << std::setfill('-') << i + 1 << "|" << std::setw(10) << this->contacts[i].getFirstName('a') << "|" << std::setw(10) << this->contacts[i].getLastName('a') << "|" << std::setw(10) << this->contacts[i].getNickname('a') << "|" << std::endl;
	}
}

std::string PhoneBook::initInterface(void)
{
	std::string timey = getCurrentTimeAsString();
	static std::string cap = "\033[1;35m " + timey + "   PhoneBook  \033[1;37m";
	std::cout << "\033[2J\033[1;1H" << std::endl;
	std::cout << "\033[1;35mWelcome To \033[3;31mT̫̤̳̫ͧ͑̓𝕿𝖍𝖊 𝕻𝖍𝖔𝖓𝖊𝕭𝖔𝖔ḳ̯͍̑ͦ!\n" << std::endl;
	std::cout << "\033[1;35";
	displayInterface();
	std::cout << "\n\033[1;37mPlease Use One Of The Commands Below : \n" << "\033[1;35m• ADD    : \033[1;37mSave a new contact.\n" << "\033[1;35m• SEARCH : \033[1;37mDisplay a specific contact.\n" << "\033[1;35m• EXIT   : \033[1;37mGuess what.\n\n" << "WARNING! : Once it's all goes black, you can never go back!" << std::endl;
	std::cout << "\033[999;1H";
	return cap;
}

bool    PhoneBook::getContactId(int id)
{
	if (this->contacts[id].getFirstName('a').empty())
		return (false);
	else
		return (true);
}

void    PhoneBook::addContact()
{
	int id;
	for (id = 0; id <= 7; id++)
	{
		if (!getContactId(id))
			break;
	}
	label:
	if (id != 8)
	{
		this->contacts[id].setFirstName();
		this->contacts[id].setLastName();
		this->contacts[id].setNickname();
		this->contacts[id].setPhoneNumber();
		this->contacts[id].setDarkestSecret();
	}
	else if (id == 8)
	{
		for (int j = 0; j < 7; j++)
		{
			this->contacts[j] = this->contacts[j + 1];
		}
		this->contacts[7].setZeroIt();
		id = 7;
		goto label;
	}
}

void PhoneBook::displayContact()
{
    std::string input;
    label:
    std::cout << "\033[2J\033[1;1H" << std::endl;
    phonebook.displayInterface();
    std::cout << "\033[999;1H";
    std::cout << "\033[3;35mChoose the index number of your Contact that's listed above : \033[3;37m";
    std::getline(std::cin, input);
    bool isNumeric = true;
    for (size_t i = 0; i < input.length(); ++i) {
        if (!std::isdigit(input[i])) {
            isNumeric = false;
            break;
        }
    }

    if (input.empty() || !isNumeric || std::atoi(input.c_str()) > 8 || std::atoi(input.c_str()) < 1) {
        goto label;
    }

    int index = std::atoi(input.c_str());
	if (this->contacts[index - 1].getFirstName('a').empty())
	{
		phonebook.initInterface();
		std::cout << "Empty Index" << std::endl;
		return ;
	}
    std::cout << "\033[2J\033[1;1H" << std::endl;
    phonebook.displayInterface();
    std::cout << "\033[3;35mFirst Name : \033[3;37m" << this->contacts[index - 1].getFirstName('b') << "\033[3;35m\nLast Name : \033[3;37m" << this->contacts[index - 1].getLastName('b') << "\033[3;35m\nNickname : \033[3;37m" << this->contacts[index - 1].getNickname('b') << "\033[3;35m\nPhone Number : \033[3;37m" << this->contacts[index - 1].getPhoneNumber('b') << "\033[3;35m\nDarkest Secret : \033[3;37m" << this->contacts[index - 1].getDarkestSecret('b') << std::endl;
    std::cout << "\033[999;1H";
	std::cout << "\033[3;35mPress Enter To go Back, Type ADD to ADD another, Type SEARCH to SEARCH another, Type EXIT to EXIT.\n";
}
