#include "Animal.class.hpp"

Animal::Animal( void ) : type("Animal") {
	std::cout << "Animal default constructor is called" << std::endl;
};

Animal::Animal(Animal const & orig) : type(orig.type) {
	std::cout << "Animal copy constructor is called" << std::endl;
};

Animal::~Animal( void ) {
	std::cout << "Animal destructor is called" << std::endl;
};

Animal & Animal::operator=(Animal const & rhs) {
	type = rhs.type;
	return(*this);
};

std::string Animal::getType() const {
	return (type);
};

void Animal::makeSound() const {
	std::cout << "ANIMAL SOUND\n" << std::endl;
};
