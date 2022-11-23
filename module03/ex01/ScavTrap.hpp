#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <string>
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
private:
	bool atGate;

public:
	ScavTrap();
	ScavTrap(std::string);
	~ScavTrap();
	void guardGate();
};

#endif