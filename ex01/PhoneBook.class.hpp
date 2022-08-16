/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:30:53 by vangirov          #+#    #+#             */
/*   Updated: 2022/08/16 19:30:42 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "mapb.hpp"
# include "Contact.class.hpp"

// class Contact;

/*
	Class PhoneBook
	It has an array of contacts.
	It can store a maximum of 8 contacts. If the user tries to add a 9th contact, 
	replace the oldest one by the new one.
	Please note that dynamic allocation is forbidden.
*/

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	/*
	If the user enters this command, they are prompted to input the information
	of the new contact one field at a time. 
	Once all the fields have been completed, add the contact to the phonebook. */
	void	addContact();

	/* Display the saved contacts as a list of 4 columns: index, first name, last
	name and nickname.
	Each column must be 10 characters wide. A pipe character (’|’) separates
	them. The text must be right-aligned. If the text is longer than the column,
	it must be truncated and the last displayable character must be replaced by a
	dot (’.’).
	Then, prompt the user again for the index of the entry to display. If the index
	is out of range or wrong, define a relevant behavior. Otherwise, display the
	contact information, one field per line. */
	int		displayAll();

	void	search();

private:
	// int		contact_num = 8;
	Contact	contacts[CONTACT_NUM];
	static std::string	trancate(std::string str, int width, std::string elipse);
	static void	printCell(std::string str, bool sep_b);
	static void	printContact(Contact& contact, int idx);
};


#endif
