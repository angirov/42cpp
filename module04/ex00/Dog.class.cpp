#include "Dog.class.hpp"

Dog::Dog( void ) { //: type("Dog") {
	std::cout << "Dog default constructor is called" << std::endl;
	type = "Dog";
};

Dog::Dog(Dog const & orig) : Animal(), type(orig.type) {
	std::cout << "Dog copy constructor is called" << std::endl;
};

Dog::~Dog( void ) {
		std::cout << "Dog destructor is called" << std::endl;
};

Dog & Dog::operator=(Dog const & rhs) {
	type = rhs.type;
	return(*this);
};

void Dog::makeSound() const {
	std::cout << "Gav gav\n" << std::endl;
};
