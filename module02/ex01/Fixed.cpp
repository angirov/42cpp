#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Copy constructor called." << std::endl;
}

// [NEW] A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const int input): val(input << fract) {
	std::cout << "Int constructor called." << std::endl;
};

// [NEW] A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
Fixed::Fixed(const float input): val(round(input * (1 << fract))) {
	std::cout << "Float constructor called." << std::endl;
};

Fixed::~Fixed() {
	std::cout << "Fixed object destructor is called." << std::endl;
}

Fixed& Fixed::operator=(const Fixed& orig) {
	std::cout << "Copy assignment operator called." << std::endl;

	if (&orig == this)
		std::cout << "### Self-assigment attempt" << std::endl;
	else
		this->val = orig.getRawBits();
	return *this;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called." << std::endl;	
	return this->val;
}

void Fixed::setRawBits( int const raw ){
	this->val = raw;
}

// [NEW] A member function that converts the fixed-point value to a floating-point value.
float Fixed::toFloat( void ) const {
	return float(this->val) ;// / (1 << fract);
}

// [NEW] A member function that converts the fixed-point value to an integer value.
int Fixed::toInt( void ) const {
	return this->val / (1 << fract);
}

// [NEW] An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<( std::ostream& out, Fixed const& fixed) {
    return out << fixed.toFloat();
}
