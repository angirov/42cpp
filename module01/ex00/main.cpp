#include "Zombie.hpp"

Zombie*	newZombie( std::string name );
void	randomChump( std::string name );

int	main()
{
	Zombie* a = newZombie("Anna");
	a->announce();

	randomChump("Bob");

	delete a;
	return 0;
}