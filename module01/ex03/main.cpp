#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		// std::cout << "Type " << club.getType().length() << std::endl;
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
		HumanB ruslan("Ruslan");
		ruslan.attack();
	}
return 0;
}