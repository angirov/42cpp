// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ScavTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ScavTrap can’t do anything if it has no hit points
// or energy points left.
// In all of these member functions, you have to print a message to describe what hap-
// pens. For example, the attack() function may display something like (of course, without
// the angle brackets):
// ScavTrap <name> attacks <target>, causing <damage> points of damage!
// The constructors and destructor must also display a message, so your peer-evaluators
// can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ): atGate(false) {
	name = "NONAME";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

// ScavTrap.cpp:19:47: warning: delegating constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
// ScavTrap::ScavTrap( void ) : ScavTrap("NONAME") {
// 	std::cout << "ScavTrap default constructor called" << std::endl;
// }

ScavTrap::ScavTrap(std::string str) : atGate(false) {
	name = str;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "ScavTrap string constructor called" << std::endl;
}

// ScavTrap::ScavTrap(ScavTrap& orig) : atGate(false) {
// 	name = orig.name;
// 	hit_points = orig.hit_points;
// 	energy_points = orig.energy_points;
// 	attack_damage = orig.attack_damage;
// }

ScavTrap::~ScavTrap( void ) {
	std::cout << "ScavTrap destructor called" << std::endl;
}

// ScavTrap& ScavTrap::operator=(ScavTrap const & rhs)
// {
// 	name = rhs.name;
// 	std::cout << "copied " << rhs.name << " to " << name << std::endl;
// 	hit_points = rhs.hit_points;
// 	energy_points = rhs.energy_points;
// 	attack_damage = rhs.attack_damage;
// 	return *this;
// }

/* This member function will display a message informing that ScavTrap is now in Gate
keeper mode. */
void ScavTrap::guardGate()
{
	if (!atGate)
		std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap was already in Gate keeper mode." << std::endl;
	atGate = true;
}
