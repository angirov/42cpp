#include "WrongCat.class.hpp"

WrongCat::WrongCat( void ) : type("WrongCat") {
		std::cout << "WrongCat default constructor is called" << std::endl;
};

WrongCat::WrongCat(WrongCat const & orig) : WrongAnimal(), type(orig.type) {
		std::cout << "WrongCat copy constructor is called" << std::endl;
};

WrongCat::~WrongCat( void ) {
		std::cout << "WrongCat destructor is called" << std::endl;
};

WrongCat & WrongCat::operator=(WrongCat const & rhs) {
	type = rhs.type;
	return(*this);
};

std::string WrongCat::getType() const {
	return (type);
};

void WrongCat::makeSound() const {
	std::cout << "Wrong Myau Myau\n" << std::endl;
};
