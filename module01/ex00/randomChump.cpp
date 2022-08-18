#include "Zombie.hpp"

/* This function creates a zombie on the STACK, name it, and the zombie announces itself */
void randomChump( std::string name )
{
	Zombie zombie(name);

	zombie.announce();
}