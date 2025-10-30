#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

bool	is_spaces(std::string str)
{
	int	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

bool	valid_string(std::string str)
{
	int	i = 0;

	while (str[i])
	{
		if (!isalnum(str[i]))
			return (false);
		i++;
	}
	if (is_spaces(str))
		return (false);
	return (true);
}

std::string	getValidInput(std::string prompt)
{
	std::string	input;

	while (true)
	{
		std::cout << prompt;
		if (!(std::getline(std::cin, input)))
		{
			if (std::cin.eof())
				std::cout << "\nEOF detected. Goodbye!" << std::endl;
			std::exit(0);
		}
		if (!input.empty() && valid_string(input))
			return (input);
	}
}

void	addCommand(Contact &contact)
{
	contact.setFirstName(getValidInput("Enter first name: "));
	contact.setLastName(getValidInput("Enter last name: "));
	contact.setNickname(getValidInput("Enter nickname: "));
	contact.setPhoneNumber(getValidInput("Enter phone number: "));
	contact.setDarkestSecret(getValidInput("Enter darkest secret: "));
}

int main()
{
	PhoneBook 	phonebook;
	std::string	command;

	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!(std::getline(std::cin, command)))
		{
			if (std::cin.eof())
				std::cout << "\nEOF detected. Goodbye!" << std::endl;
			std::exit(0);
		}
		if (command == "ADD")
		{
			Contact	contact;
			addCommand(contact);
			phonebook.addContact(contact);
		}
		else if (command == "SEARCH")
			phonebook.searchContacts();
		else if (command == "EXIT")
			break ;
	}
	return (0);
}