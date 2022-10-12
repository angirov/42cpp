#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	std::cout << "Fixed object default constructor is called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Fixed object copy constructor is called." << std::endl;
}

Fixed::Fixed(const int input): val(input << 8) {};

Fixed::Fixed(const float input): val(round(input * (1 << 8))) {};

Fixed::~Fixed() {
	std::cout << "Fixed object destructor is called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& orig) {
	this->val = orig.val;
	return *this;
}

int Fixed::getRawBits( void ) const{
	return this->val;
}

void Fixed::setRawBits( int const raw ){
	this->val = raw;
}

float Fixed::toFloat( void ) const {
	return float(this->val) / (1 << 8);
}

int Fixed::toInt( void ) const {
	return this->val / (1 << 8);
}

std::ostream & operator<<( std::ostream& out, Fixed const& fixed) {
    return out << fixed.toFloat();
}