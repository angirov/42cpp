#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	std::cout << "Fixed object default constructor is called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Fixed object copy constructor is called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& orig) {
	this->val = orig.val;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Fixed object destructor is called." << std::endl;
}

int Fixed::getRawBits( void ) const{
	return this->val;
}

void Fixed::setRawBits( int const raw ){
	this->val = raw;
}

