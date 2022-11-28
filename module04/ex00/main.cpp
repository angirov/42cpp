#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << j->getType() << " " << std::endl; // WHY the type stays Animal??????
	std::cout << j->Animal::getType() << " " << std::endl; // WHY the type stays Animal??????
	std::cout << i->getType() << " " << std::endl;
	std::cout << i->Animal::getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	wa->makeSound();
	wc->makeSound();

	delete i;
	delete j; 
	delete meta;
	return 0;
}

// https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function