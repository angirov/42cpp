#include "Zombie.hpp"
#include <vector>

Zombie* zombieHorde( int N, std::string name );

int	main()
{
	int N = 5;

	Zombie *horde = zombieHorde(N, "Noname");
	std::vector<Zombie> zv = *(std::vector<Zombie> *)horde;
	for (Zombie& z : zv)
	{
		z.announce();
	}

	delete (std::vector<Zombie> *)horde;
	return 0;
}