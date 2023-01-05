#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Copy constructor called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& orig) {
	std::cout << "Copy assignment operator called." << std::endl;

	if (&orig == this)
		std::cout << "### Self-assigment attempt" << std::endl;
	else
		this->val = orig.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Fixed object destructor is called." << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called." << std::endl;	
	return this->val;
}

void Fixed::setRawBits( int const raw ){
	this->val = raw;
}

