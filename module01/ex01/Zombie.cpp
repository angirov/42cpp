#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Default Zombie NONAME is constructed" << std::endl;
}
Zombie::Zombie( std::string name ) : name( name ) 
{
	std::cout << "Zombie " << this->name << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is destructed" << std::endl;
}

void	Zombie::setName( std::string name )
{
	this->name = name;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
