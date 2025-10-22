#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
private:
	Contact	contacts[8];
	int		nex_index;
	int		count;

public:
	PhoneBook();
	void	addContact(Contact new_contact);
	void	searchContacts();
};
