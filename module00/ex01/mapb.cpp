/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapb.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:49:48 by vangirov          #+#    #+#             */
/*   Updated: 2023/01/04 11:51:44 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	On program start-up, the phonebook is empty and the user is prompted to enter one
	of three commands. The program only accepts ADD, SEARCH and EXIT.
	The program quits and the contacts are lost forever! Any other input is discarded.
	Once a command has been correctly executed, the program waits for another one. It
	stops when the user inputs EXIT. */

#include "mapb.hpp"

std::string int2str (int n)
{
	std::ostringstream ss;
	ss << n;
	return ss.str();
}

int	main()
{
	PhoneBook myPB;

	std::string command;
	while (1)
	{
		std::cout << "Enter you command [ ADD/a | SEARCH:/s | EXIT/e ]: ";
		std::cin >> command;
		if (command == "EXIT" || command == "e")
			break ;
		else if (command == "SEARCH" || command == "s")
			myPB.search();
		else if (command == "ADD" || command == "a")
			myPB.addContact();
	}
	
}
