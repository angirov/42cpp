/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:59:05 by vangirov          #+#    #+#             */
/*   Updated: 2022/10/05 11:50:53 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

PhoneBook::PhoneBook() {}

/* Display the saved contacts as a list of 4 columns: index, first name, last
		name and nickname.
		Each column must be 10 characters wide. A pipe character (’|’) separates
		them. The text must be right-aligned. If the text is longer than the column,
		it must be truncated and the last displayable character must be replaced by a
		dot (’.’).
		Then, prompt the user again for the index of the entry to display. If the index
		is out of range or wrong, define a relevant behavior. Otherwise, display the
		contact information, one field per line. */

void	PhoneBook::search() {
	if (!PhoneBook::displayAll())
		return;
	std::cout << "Insert index of the contact to display: " << std::endl;
	int index = -1;
	while(!(std::cin >> index && 
			index >= 0 && index < Contact::filled()))
	{
		std::cout << "Bad value!\n";
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
	std::cout << ">> Phone Number: " << this->contacts[index].getPhoneNumber() << std::endl;
}

int	PhoneBook::displayAll()
{
	int filled = Contact::filled();

	if (!filled)
		std::cout << ">> The PhoneBook is empty!" << std::endl;
	else
	{
		for (int i = 0; i < filled; i++)
		{
			PhoneBook::printContact(this->contacts[i], i);
		}
	}
	std::cout << ">>>>> Contacts added: " << Contact::getAddCounter() << " >>>>>" << std::endl; 
	return filled;
}

std::string	PhoneBook::trancate(std::string str, std::string::size_type width, std::string elipse)
{
	if (str.length() > width)
		return (str.substr(0, width - elipse.length()) + elipse);
	return str;
}

void	PhoneBook::printCell(std::string str, bool sep_b)
{
	str = trancate(str, COL_WIDTH, ".");
	std::string col_sep(1, COL_SEP);
	std::cout << std::setw(10) << std::right << str;
	if (sep_b)
		std::cout << col_sep;
	else
		std::cout << std::endl;
}

void	PhoneBook::printContact(Contact& contact, int idx)
{
	PhoneBook::printCell(std::to_string(idx), true);
	PhoneBook::printCell(contact.getFirstName(), true);
	PhoneBook::printCell(contact.getLastName(), true);
	PhoneBook::printCell(contact.getNickName(), false);
}

void	PhoneBook::addContact()
{
	std::string fieldNames[] = {"First Name",
								"Last Name",
								"Nickname",
								"Phone Number",
								"Darkest Secret"};
	std::string	toFill[5];
	int toAdd = Contact::getAddCounter() % CONTACT_NUM;
	Contact& contact = this->contacts[toAdd];
	for (int i = 0; i < 5; i++)
	{
		std::cout << ">> Please enter the " << fieldNames[i] << ": " << std::endl;
		std::cin >> toFill[i];
		std::cin.ignore();
	}
	contact.setContact(toFill[0],
						toFill[1],
						toFill[2],
						toFill[3],
						toFill[4]);
	return;
}

PhoneBook::~PhoneBook() {}
