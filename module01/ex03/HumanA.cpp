
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon) 
{
    std::cout << ">>> Constructed HumanA " << name << " with " << weapon.getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << ">>> HumanA destructor is called" << std::endl;
}

void	HumanA::attack()
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}