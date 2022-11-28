#include "Animal.class.hpp"
#include "Cat.class.hpp"
#include "Dog.class.hpp"

#define ARR_LEN 10

int main()
{
	const Animal* meta = new Animal();
	std::cout << "@@@ Type of meta: ";
	std::cout << meta->getType() << std::endl;

	const Animal* d = new Dog();
	std::cout << "@@@ Type of d: " << d->getType() << std::endl;
	std::cout << "@@@ Type of d: " << d->Animal::getType() << std::endl;
	d->newIdea("Cogito ergo sum");
	std::cout << "### Ideas of d: " << std::endl;
	d->printIdeas();

	Animal* c = new Cat();
	*c = *d;
	std::cout << "### Ideas of c: " << std::endl;
	c->printIdeas();
	c->newIdea("Errare humanum est");
	std::cout << "### New ideas of c: " << std::endl;
	c->printIdeas();

	std::cout << "### Any new deas of d? " << std::endl;
	d->printIdeas();

	delete d;
	delete c;
	delete meta;

	std::cout << "===== Array experiment starts =====" << std::endl;
	Animal * array[ARR_LEN];
	for (int i = 0; i < ARR_LEN; i++)
	{
		if (i % 2 == 0)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}
	for (int i = 0; i < ARR_LEN; i++)
	{
		std::cout << "[" << i << "] Type: " << array[i]->getType() << std::endl;
	}
	for (int i = 0; i < ARR_LEN; i++)
	{
		delete array[i];
	}
	return 0;
}
