
#include "HumanB.hpp"
#include "Weapon.hpp"

// HumanB::HumanB()
// {
//     this->name = "NONAME";
//     this->weapon = new Weapon;
// }

HumanB::HumanB(std::string name) : name(name) 
{
    // std::cout << "Constructed HumanB " << this->name << " with " << this->weapon.getType() << std::endl;
}

HumanB::~HumanB() {}

void	HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void	HumanB::attack()
{
    if (this->weapon->getType().length())
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " tries to attack but has no weapon" << std::endl;
}