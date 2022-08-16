/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:32:28 by vangirov          #+#    #+#             */
/*   Updated: 2022/08/16 19:35:10 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include "mapb.hpp"

/*
	Class Contact
	The contact fields are: 
	- first name, 
	- last name, 
	- nickname, 
	- phone number, and
	- darkest secret. 
	A saved contact can’t have empty fields.
*/

class Contact {
public:
	Contact();
	~Contact();

	void	setContact(std::string firstName,
						std::string lastName,
						std::string nickName,
						std::string phoneNumber,
						std::string darkestSecret);
	static int	getAddCounter();
	static int	filled();

	std::string	getFirstName();
	std::string	getLastName();
	std::string	getNickName();
	std::string	getPhoneNumber();

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;

	static int	addCounter;
};

#endif