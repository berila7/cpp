#include <iostream>
#include <cstdlib>
#include "PhoneBook.hpp"

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
		if (!input.empty())
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
		if (!(std::cin >> command))
		{
			if (std::cin.eof())
				std::cout << "\nEOF detected. Goodbye!" << std::endl;
			std::exit(0);
		}
		if (command == "ADD")
		{
			Contact	contact;
			std::cin.ignore(1000, '\n');
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