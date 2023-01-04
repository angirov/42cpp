#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

#include <iostream>

int main()
{
	{
		std::cout << "===== test00: HumanA =====" << std::endl;
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		std::cout << "===== test01: HumanB =====" << std::endl;
		Weapon club2 = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club2);
		club2.setType("some other type of club");
		jim.attack();
		jim.attack();
	}
	{
		std::cout << "===== test02: HumanB without weapon =====" << std::endl;
		HumanB ruslan("Ruslan");
		ruslan.attack();
	}
	return 0;
}