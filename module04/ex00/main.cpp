#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

#include "WrongAnimal.class.hpp"
#include "WrongCat.class.hpp"

int main()
{
	const Animal* a = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << std::endl;
	std::cout << "Dog's (   own   ) type: "  << d->getType() << std::endl; // WHY the type stays Animal??????
	std::cout << "Dog's (as animal) type: "  << d->Animal::getType() << std::endl; // WHY the type stays Animal??????
	std::cout << "Cat's (   own   ) type: "  << c->getType() << std::endl;
	std::cout << "Cat's (as animal) type: "  << c->Animal::getType() << std::endl;
	std::cout << std::endl;
	std::cout << "Dog's sound: ";
	d->makeSound();
	std::cout << "Cat's sound: ";
	c->makeSound(); //will output the cat sound!
	std::cout << "Animal's sound: ";
	a->makeSound();

	std::cout << "Wrong animal's sound: ";
	wa->makeSound();
	std::cout << "Wrong cat's sound: ";
	wc->makeSound();

	delete d; 
	delete c;
	delete a;
	return 0;
}

// https://stackoverflow.com/questions/357307/how-to-call-a-parent-class-function-from-derived-class-function