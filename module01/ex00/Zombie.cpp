#include "Zombie.hpp"

Zombie::Zombie() : name( "noname" ) {}
Zombie::Zombie( std::string name ) : name( name ) {}

Zombie::~Zombie()
{
	std::cout << "Zombie " << this->name << " is destructed" << std::endl;
}

void	Zombie::announce( void )
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
