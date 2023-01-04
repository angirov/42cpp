#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name) : name(name) 
{
    weapon = NULL;
    std::cout << ">>> HumanB constructor is called" << std::endl;
}

HumanB::~HumanB() {
    std::cout << ">>> HumanB destructor is called" << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void	HumanB::attack()
{
    if (weapon && weapon->getType().length())
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    else
        std::cout << name << " tries to attack but has no weapon" << std::endl;
}