#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap {
private:
	std::string name;
	int hit_points; // (10), represent the health of the ClapTrap
	int energy_points; // (10)
	int attack_damage; // (0)

public:
	ClapTrap( void );
	ClapTrap(std::string);
	ClapTrap(ClapTrap&);
	~ClapTrap();
	ClapTrap& operator=(ClapTrap const &);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif