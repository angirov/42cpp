#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    this->type = name;
}

Weapon::Weapon() {}

Weapon::~Weapon() {}

std::string const &Weapon::getType()
{
    return this->type;
}

void	Weapon::setType(std::string type)
{
    this->type = type;
}
