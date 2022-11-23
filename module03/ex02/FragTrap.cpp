// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When FragTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, FragTrap can’t do anything if it has no hit points
// or energy points left.
// In all of these member functions, you have to print a message to describe what hap-
// pens. For example, the attack() function may display something like (of course, without
// the angle brackets):
// FragTrap <name> attacks <target>, causing <damage> points of damage!
// The constructors and destructor must also display a message, so your peer-evaluators
// can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) {
	name = "NONAME";
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "FragTrap default constructor called" << std::endl;
}

// FragTrap.cpp:19:47: warning: delegating constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
// FragTrap::FragTrap( void ) : FragTrap("NONAME") {
// 	std::cout << "FragTrap default constructor called" << std::endl;
// }

FragTrap::FragTrap(std::string str) {
	name = str;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap string constructor called" << std::endl;
}

// FragTrap::FragTrap(FragTrap& orig) : atGate(false) {
// 	name = orig.name;
// 	hit_points = orig.hit_points;
// 	energy_points = orig.energy_points;
// 	attack_damage = orig.attack_damage;
// }

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap destructor called" << std::endl;
}

// FragTrap& FragTrap::operator=(FragTrap const & rhs)
// {
// 	name = rhs.name;
// 	std::cout << "copied " << rhs.name << " to " << name << std::endl;
// 	hit_points = rhs.hit_points;
// 	energy_points = rhs.energy_points;
// 	attack_damage = rhs.attack_damage;
// 	return *this;
// }

/* This member function will display a message informing that FragTrap is now in Gate
keeper mode. */
void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap says: \"High five guys\"." << std::endl;
}
