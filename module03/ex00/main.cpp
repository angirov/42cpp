#include <iostream>
#include "ClapTrap.hpp"

int main()
{
	ClapTrap ct("Clappy");

	for (int i=0; i < 5; i++)
		ct.attack("Trappy");
	ClapTrap ct2(ct);
	
	// ct2 = ct;


	ct2.attack("Trappy2");
	ClapTrap ct3;
	ct3.attack("Trappy3");
}