#include "Contact.hpp"
#include <iostream>

void	Contact::setFirstName(std::string value)
{
	first_name = value;
}

void	Contact::setLastName(std::string value)
{
	last_name = value;
}

void	Contact::setNickname(std::string value)
{
	nickname = value;
}

void	Contact::setPhoneNumber(std::string value)
{
	phone_number = value;
}

void	Contact::setDarkestSecret(std::string value)
{
	darkest_secret = value;
}

std::string	Contact::getFirstName()
{
	return (first_name);
}

std::string	Contact::getLastName()
{
	return (last_name);
}

std::string Contact::getNickname()
{
	return (nickname);
}

std::string Contact::getPhoneNumber()
{
	return (phone_number);
}

std::string Contact::getDarkestSecret()
{
	return (darkest_secret);
}
