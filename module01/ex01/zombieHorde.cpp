#include "Zombie.hpp"
// #include <vector>


Zombie* zombieHorde( int N, std::string name )
{
	Zombie* horde = new Zombie[N];
	
	std::cout << "Constructed all zombies" << std::endl;
	for (int i=0; i < N; i++)
	{
		horde[i].setName(name);
	}
	return &horde[0];
}

// Zombie *zombieHorde( int N, std::string name )
// {
// 	std::vector<Zombie> *horde = new std::vector<Zombie>;
// 	horde->reserve(N);
// 	std::cout << "Allocated the horde" << std::endl;

// 	std::cout << "Size of horde: " << sizeof(*horde) << std::endl;


// 	for (int i = 0; i < N; i++)
// 	{
// 		horde->__emplace_back(name);
// 	}
// 	std::cout << ">>> Created a horde\n";
// 	// for (Zombie& z : *horde)
// 	// {
// 	// 	z.announce();
// 	// }
// 	// std::cout << ">>> Printed the horde\n";
// 	return (Zombie *)horde;
// }
