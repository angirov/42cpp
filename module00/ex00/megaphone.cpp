/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vangirov <vangirov@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:49:57 by vangirov          #+#    #+#             */
/*   Updated: 2023/01/04 11:33:12 by vangirov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

char* str2upper(char* s)
{
	for (int i = 0; s[i]; i++)
			s[i] = toupper(s[i]);
	return s; 
}

int main(int argc, char **argv)
{
	for (int i = 1; argv[i]; i++)
	{
		std::cout << str2upper(argv[i]);
	}
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
