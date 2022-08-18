#include "Zombie.hpp"

Zombie::Zombie() : name( "noname" ) 
{
	std::cout << "Zombie " << this->name << " is constructed" << std::endl;
}
Zombie::Zombie( std::string name ) : name( name ) 
{
	std::cout << "Zombie " << this->name << " is constructed" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is destructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
