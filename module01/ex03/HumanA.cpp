
#include "HumanA.hpp"
#include "Weapon.hpp"

// HumanA::HumanA()
// {
//     this->name = "NONAME";
//     this->weapon = new Weapon;
// }

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) 
{
    // std::cout << "Constructed HumanA " << this->name << " with " << this->weapon.getType() << std::endl;
}

HumanA::~HumanA() {}

void	HumanA::attack()
{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}