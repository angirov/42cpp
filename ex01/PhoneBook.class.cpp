/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:59:05 by vangirov          #+#    #+#             */
/*   Updated: 2022/08/15 21:57:00 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include "Contact.class.hpp"

// enum col {
// 	index, 
// 	first_name, 
// 	last,
// 	name,
// 	nickname
// };

// static std::string headers[] = { "index", "first name", "last name", "nickname" };

PhoneBook::PhoneBook()
{
	std::cout << "create PB" << std::endl;
}

/* Display the saved contacts as a list of 4 columns: index, first name, last
		name and nickname.
		Each column must be 10 characters wide. A pipe character (’|’) separates
		them. The text must be right-aligned. If the text is longer than the column,
		it must be truncated and the last displayable character must be replaced by a
		dot (’.’).
		Then, prompt the user again for the index of the entry to display. If the index
		is out of range or wrong, define a relevant behavior. Otherwise, display the
		contact information, one field per line. */

void	PhoneBook::displayAll()
{
	for (int i; i < CONTACT_NUM; i++)
	{
		PhoneBook::printContact(this->contacts[i], i);
	}
}

void	PhoneBook::printContact(Contact& contact, int idx)
{
	std::string sep(1, COL_SEP);

	std::cout << idx
	<< sep << contact.getFirstName()
	<< sep << contact.getLastName()
	<< sep << contact.getNickName()
	<< std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << "destroy PB" << std::endl;
}