#include "Cat.class.hpp"

Cat::Cat( void ) : type("Cat") {
		std::cout << "Cat default constructor is called" << std::endl;
};

Cat::Cat(Cat const & orig) : Animal(), type(orig.type) {
		std::cout << "Cat copy constructor is called" << std::endl;
};

Cat::~Cat( void ) {
		std::cout << "Cat destructor is called" << std::endl;
};

Cat & Cat::operator=(Cat const & rhs) {
	type = rhs.type;
	return(*this);
};

std::string Cat::getType() const {
	return (type);
};

void Cat::makeSound() const {
	std::cout << "Myau Myau\n" << std::endl;
};
