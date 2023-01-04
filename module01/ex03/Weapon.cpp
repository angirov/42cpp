#include "Weapon.hpp"

Weapon::Weapon(std::string name)
{
    this->type = name;
    std::cout << ">>> Weapon constructor is called" << std::endl;
}

Weapon::Weapon() {
    std::cout << ">>> Weapon default constructor is called" << std::endl;
}

Weapon::~Weapon() {
    std::cout << ">>> Weapon destructor is called" << std::endl;
}

std::string const &Weapon::getType() const
{
    return this->type;
}

void	Weapon::setType(std::string type)
{
    this->type = type;
}
