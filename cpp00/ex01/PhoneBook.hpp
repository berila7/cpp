#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		next_index;
	int		count;

public:
	PhoneBook();
	void	addContact(Contact new_contact);
	void	searchContacts();
};

#endif