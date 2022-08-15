/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapb.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:49:48 by vangirov          #+#    #+#             */
/*   Updated: 2022/08/15 19:17:06 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* On program start-up, the phonebook is empty and the user is prompted to enter one
of three commands. The program only accepts ADD, SEARCH and EXIT.
• EXIT
◦ The program quits and the contacts are lost forever!
• Any other input is discarded.
Once a command has been correctly executed, the program waits for another one. It
stops when the user inputs EXIT. */

#include "mapb.hpp"

int	main()
{
	PhoneBook myPB;

	myPB.displayAll();
}