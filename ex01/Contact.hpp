#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
private:
	std::string	first_name;
	std::string last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
public:
	void	setFirstName(std::string value);
	void	setLastName(std::string value);
	void	setNickname(std::string value);
	void	setPhoneNumber(std::string value);
	void	setDarkestSecret(std::string value);

	std::string	getFirstName();
	std::string getLastName();
	std::string getNickname();
	std::string getPhoneNumber();
	std::string getDarkestSecret();
};

#endif