#include "Animal.class.hpp"

Animal::Animal( void ) : type("Animal") {
	std::cout << "Animal default constructor is called" << std::endl;
	brain = new Brain();
};

Animal::Animal(Animal const & orig) : type(orig.type) {
	std::cout << "Animal copy constructor is called" << std::endl;
};

Animal::~Animal( void ) {
	std::cout << "Animal destructor is called" << std::endl;
	delete brain;
};

Animal & Animal::operator=(Animal const & rhs) {
	std::cout << ">>> Animal copy operator is called" << std::endl;
	type = rhs.type;
	*brain = *rhs.brain;
	return(*this);
};

std::string Animal::getType() const {
	return (type);
};

void Animal::makeSound() const {
	std::cout << "ANIMAL SOUND\n" << std::endl;
};

void Animal::newIdea(std::string idea) const {
	brain->newIdea(idea);
};

std::string Animal::getIdea(int index) const {
	return (brain->getIdea(index));
};

void Animal::printIdeas() const {
	brain->printIdeas();
};
