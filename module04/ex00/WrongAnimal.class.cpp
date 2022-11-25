#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal( void ) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor is called" << std::endl;
};

WrongAnimal::WrongAnimal(WrongAnimal const & orig) : type(orig.type) {
	std::cout << "WrongAnimal copy constructor is called" << std::endl;
};

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor is called" << std::endl;
};

WrongAnimal & WrongAnimal::operator=(WrongAnimal const & rhs) {
	type = rhs.type;
	return(*this);
};

std::string WrongAnimal::getType() const {
	return (type);
};

void WrongAnimal::makeSound() const {
	std::cout << "Wrong ANIMAL SOUND\n" << std::endl;
};
