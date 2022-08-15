/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:37:08 by vangirov          #+#    #+#             */
/*   Updated: 2022/08/15 22:08:45 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapb.hpp"

int	Contact::oldest = 0;
int	Contact::counter = 0;

Contact::Contact() :
				firstName("default"),
				lastName("default"),
				nickName("default"),
				phoneNumber("default"),
				darkestSecret("default")
{
	Contact::counter++;
	std::cout << "Created contact [" << Contact::counter << "]" << std::endl;
}

Contact::Contact(std::string firstName,
				std::string lastName,
				std::string nickName,
				std::string phoneNumber,
				std::string darkestSecret) :
				firstName(firstName),
				lastName(lastName),
				nickName(nickName),
				phoneNumber(phoneNumber),
				darkestSecret(darkestSecret)
{
	std::cout << "Created contact [" << Contact::counter << "]" << std::endl;
}

Contact::~Contact()
{
}

int	Contact::getCounter()
{
	return Contact::counter;
}

int	Contact::getOldest()
{
	return Contact::oldest;
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

std::string	Contact::getDarkestSecret()
{
	return this->darkestSecret;
}
