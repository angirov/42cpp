/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:37:08 by vangirov          #+#    #+#             */
/*   Updated: 2022/10/05 11:02:46 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapb.hpp"

int	Contact::addCounter = 0;

Contact::Contact() :
				firstName("default"),
				lastName("default"),
				nickName("default"),
				phoneNumber("default"),
				darkestSecret("default")
{
}

void	Contact::setContact(std::string firstName,
							std::string lastName,
							std::string nickName,
							std::string phoneNumber,
							std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
	Contact::addCounter++;
}

Contact::~Contact()
{
}

int	Contact::filled()
{
	if (Contact::addCounter < 8)
		return Contact::addCounter;
	else
		return 8;
}

int	Contact::getAddCounter()
{
	return Contact::addCounter;
}

std::string	Contact::getFirstName()
{
	return this->firstName;
}

std::string	Contact::getLastName()
{
	return this->lastName;
}

std::string	Contact::getNickName()
{
	return this->nickName;
}

std::string	Contact::getPhoneNumber()
{
	return this->phoneNumber;
}
