#include <iostream>
#include <iomanip>
#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	nex_index = 0;
	count = 0;
}

std::string	formatField(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}

void	PhoneBook::addContact(Contact new_contact)
{
	contacts[nex_index] = new_contact;
	nex_index = (nex_index + 1) % 8;
	if (count < 8)
		count++;
}

void	PhoneBook::searchContacts()
{
	int	index;

	if (count == 0)
	{
		std::cout << "No contacts saved yet!" << std::endl;
		return ;
	}
	std::cout << std::setw(10) << "index" << "|";
	std::cout << std::setw(10) << "first name" << "|";
	std::cout << std::setw(10) << "last name" << "|";
	std::cout << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < count; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << formatField(contacts[i].getNickname()) << std::endl;
	}
	std::cout << "Enter contact index: ";
	if (!(std::cin >> index))
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		std::cout << "Invalid input!" << std::endl;
		return ;
	}
	if (index >= 0 && index <= count -1)
	{
		std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
		std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
		std::cout << "nickname: " << contacts[index].getNickname() << std::endl;
		std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
	}
	else
		std::cout << "Invalid index!" << std::endl;
	std::cin.ignore(1000, '\n');
	return ;
}