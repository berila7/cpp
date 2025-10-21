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

std::string	Contact::getFirstName()
{
	return (first_name);
}

std::string	Contact::getLastName()
{
	return (last_name);
}
