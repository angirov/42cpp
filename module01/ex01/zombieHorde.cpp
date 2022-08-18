#include "Zombie.hpp"
#include <vector>


// Zombie* zombieHorde( int N, std::string name )
// {
// 	Zombie* horde = new Zombie[10];
	
// 	for (int i=0; i < 10; i++)
// 	{
// 		Zombie oz = horde[i];
// 		Zombie* nz = new Zombie(name);
// 		horde[i] = *nz;
// 		delete &oz;
// 		horde[i].announce();
// 	}
// 	return &horde[0];
// }

Zombie *zombieHorde( int N, std::string name )
{
	std::vector<Zombie> *horde = new std::vector<Zombie>;
	horde->reserve(N);
	for (int i = 0; i < N; i++)
	{
		horde->emplace_back(name);
	}
	std::cout << ">>> Created a horde\n";
	// for (Zombie& z : *horde)
	// {
	// 	z.announce();
	// }
	// std::cout << ">>> Printed the horde\n";
	return (Zombie *)horde;
}
