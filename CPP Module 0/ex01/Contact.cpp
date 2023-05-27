#include "Contact.hpp"
#include "PhoneBook.hpp"
//Finish EdgeControls and Aesthetics

Contact::Contact(){}

bool isNumber(const std::string& s)
{
    return (s.find_first_not_of("0123456789") == std::string::npos);
}

void	Contact::setFirstName()
{
	std::string firstName;
	std::cout << "\033[2J\033[1;1H" << std::endl;
	phonebook.displayInterface();
	std::cout << "\033[999;1H";
	label:
	std::cout << "\033[3;35mPlease tell me your New Soul Bou-... New Contact's First Name : \033[3;37m";
	std::getline(std::cin, firstName);
	if (firstName.empty())
		goto label;
	std::cout << "\033[3;35mThe name... " << firstName << "... how strange..." << std::endl;
	this->firstName = firstName;
}

void	Contact::setLastName()
{
	std::string lastName;
	std::cout << "\033[2J\033[1;1H" << std::endl;
	phonebook.displayInterface();
	std::cout << "\033[999;1H";
	label:
	std::cout << "\033[3;35mWhat is the Last Name of this Contact of yours : \033[1;37m";
	std::getline(std::cin, lastName);
	if (lastName.empty())
		goto label;
	std::cout << "\033[3;35mHmm... Sounds like a royal bloodline..." << std::endl;
	this->lastName = lastName;
}

void	Contact::setNickname()
{
	std::string nickname;
	std::cout << "\033[2J\033[1;1H" << std::endl;
	phonebook.displayInterface();
	std::cout << "\033[999;1H";
	label:
	std::cout << "\033[3;35mYou can't identify everyone just by their name... Tell me who is " << this->firstName << " for you and you only? What's " << this->firstName << "'s Nickname? : \033[1;37m";
	std::getline(std::cin, nickname);
	if (nickname.empty())
		goto label;
	std::cout << "\033[3;35mA choice of wise..." << std::endl;
	this->nickname = nickname;
}

void	Contact::setPhoneNumber()
{
	std::string phoneNumber;
	std::cout << "\033[2J\033[1;1H" << std::endl;
	phonebook.displayInterface();
	std::cout << "\033[999;1H";
	label:
	std::cout << "\033[3;35mWhat's your contacts Phone Number? : \033[1;37m";
	std::getline(std::cin, phoneNumber);
	if (phoneNumber.empty() || !isNumber(phoneNumber)){
		std::cout << "\033[3;35mDon't try to fool me,\033[3;31mḠ̷͕̣̲͋̀͐̋̌͝i̵̛̬̘͚̦͕̋̋̉̑͆̊̍̇͊͘͝v̸̆̎̓̒͂̑ė̵̹̎̒̈́̄̓̋ ̸̅̋͛́̿̑̋m̶̛̆͑͌̍̈́͐ȅ̴̛̟͛͂̓̈́̉̀̕ ̴̡͕͔͙̯̗̙́̾̄͝t̵̡̧̖͖̜͕͖́̀h̷̪͕̼̥̱̪͕̻̫̖̀͋̊̈́̏̏̅̔͜e̷̥̭̟̩̥͖͔̓̅͌̉̊͜ ̵̨̡̡̹̞͉̮͓̳̥̹͛̈͌͆̓̈́̈̑̌̕ͅņ̶̛̖̩̪̲̮̩̓͂̾̄̄̈̑̾̓̕͝͝͠ư̵̛̄̽̂̐̈́̑͋͘m̷̡̢̟̳͖̙͂͌̇̓̓̈́̈̈̾̓̎͘̚͜b̶̨̹̟̰̔̔̓̈́͒̈́͗̓̐͌͝͝͠͝ę̴̘̘̲̫̠̈́̃̐̏͋̈́͑̓͜͝r̷̢̜̘̝̓͛͑͋s̸̢̛̩̣͋͌͐͌͌̊̇̿̔̐̍͝!!!" << std::endl;
		goto label;
	}
	std::cout << "\033[3;35mWell done darling, you are almost there!" << std::endl;
	this->phoneNumber = phoneNumber; 
}

void	Contact::setDarkestSecret()
{
	std::string darkestSecret;
	std::cout << "\033[2J\033[1;1H" << std::endl;
	phonebook.displayInterface();
	std::cout << "\033[999;1H";
	label:
	std::cout << "\033[1;35mWell, we are almost done... You only know someone as much as you know their darkness... Tell me what's your Contact's Darkest Secret? : \033[1;37m";
	std::getline(std::cin, darkestSecret);
	if (darkestSecret.empty())
		goto label;
	this->darkestSecret = darkestSecret;
}

std::string	Contact::getFirstName(char a)
{
	if (a == 'a' && !firstName.empty())
	{
		size_t i;
		size_t size = firstName.length();
		std::string shorter;
		for (i = 0; i <= 9; i++)
		{
			if (i == 9 && size > 10)
				break;
			else
				shorter += firstName[i];
		}
 		if (i > 0 && i == 9 && size > 10)
			shorter += '.';
		return shorter;
	}
	else
		return firstName;
}

std::string	Contact::getLastName(char a)
{
	if (a == 'a' && !lastName.empty())
	{
		size_t i;
		size_t size = lastName.length();
		std::string shorter;
		for (i = 0; i <= 9; i++)
		{
			if (i == 9 && size > 10)
				break;
			else
				shorter += lastName[i];
		}
 		if (i > 0 && i == 9 && size > 10)
			shorter += '.';
		return shorter;
	}
	else
		return lastName;
}

std::string	Contact::getNickname(char a)
{
	if (a == 'a' && !nickname.empty())
	{
		size_t i;
		size_t size = nickname.length();
		std::string shorter;
		for (i = 0; i <= 9; i++)
		{
			if (i == 9 && size > 10)
				break;
			else
				shorter += nickname[i];
		}
 		if (i > 0 && i == 9 && size > 10)
			shorter += '.';
		return shorter;
	}
	else
		return nickname;
}

std::string	Contact::getPhoneNumber(char a)
{
	if (a == 'a' && !phoneNumber.empty())
	{
		size_t i;
		size_t size = phoneNumber.length();
		std::string shorter;
		for (i = 0; i <= 9; i++)
		{
			if (i == 9 && size > 10)
				break;
			else
				shorter += phoneNumber[i];
		}
 		if (i > 0 && i == 9 && size > 10)
			shorter += '.';
		return shorter;
	}
	else
		return phoneNumber;
}

std::string	Contact::getDarkestSecret(char a)
{
	if (a == 'a' && !darkestSecret.empty())
	{
		size_t i;
		size_t size = darkestSecret.length();
		std::string shorter;
		for (i = 0; i <= 9; i++)
		{
			if (i == 9 && size > 10)
				break;
			else
				shorter += darkestSecret[i];
		}
 		if (i > 0 && i == 9 && size > 10)
			shorter += '.';
		return shorter;
	}
	else
		return darkestSecret;
}