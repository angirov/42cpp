// When ClapTrack attacks, it causes its target to lose <attack damage> hit points.
// When ClapTrap repairs itself, it gets <amount> hit points back. Attacking and repairing
// cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
// or energy points left.
// In all of these member functions, you have to print a message to describe what hap-
// pens. For example, the attack() function may display something like (of course, without
// the angle brackets):
// ClapTrap <name> attacks <target>, causing <damage> points of damage!
// The constructors and destructor must also display a message, so your peer-evaluators
// can easily see they have been called.
// Implement and turn in your own tests to ensure your code works as expected.

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : name("NONAME"), hit_points(10), energy_points(10), attack_damage(0) {
	std::cout << "ClapTrap default constructor called" << std::endl;
}

// ClapTrap.cpp:19:47: warning: delegating constructors only available with ‘-std=c++11’ or ‘-std=gnu++11’
// ClapTrap::ClapTrap( void ) : ClapTrap("NONAME") {
// 	std::cout << "ClapTrap default constructor called" << std::endl;
// }

ClapTrap::ClapTrap(std::string str): name(str), hit_points(10), energy_points(10), attack_damage(0) {
	name = str;
	std::cout << "ClapTrap string constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap& orig) : 
	name(orig.name),
	hit_points(orig.hit_points), 
	energy_points(orig.energy_points), 
	attack_damage(orig.attack_damage) {
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs)
{
	name = rhs.name;
	std::cout << "copied " << rhs.name << " to " << name << std::endl;
	hit_points = rhs.hit_points;
	energy_points = rhs.energy_points;
	attack_damage = rhs.attack_damage;
	return *this;
}

void ClapTrap::attack(const std::string& target) 
{
	if (hit_points <= 0 || energy_points <= 0)
	{
		std::cout << "Cannot attack because of lacking points." << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	hit_points -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0 || energy_points <= 0)
	{
		std::cout << "Cannot be repaied because of lacking points." << std::endl;
		return;
	}
	hit_points += amount;
}
