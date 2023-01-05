#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Copy constructor called." << std::endl;
}

Fixed::Fixed(const int input): val(input << fract) {
	std::cout << "Int constructor called." << std::endl;
};

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

// [NEW] The 6 comparison operators: >, <, >=, <=, == and !=.
bool Fixed::operator>(const Fixed &other) const {
	return this->val > other.val;
}
bool Fixed::operator<(const Fixed &other) const {
	return this->val < other.val;
}
bool Fixed::operator>=(const Fixed &other) const {
	return this->val >= other.val;
}
bool Fixed::operator<=(const Fixed &other) const {
	return this->val <= other.val;
}
bool Fixed::operator==(const Fixed &other) const {
	return this->val == other.val;
}
bool Fixed::operator!=(const Fixed &other) const {
	return this->val != other.val;
}

// [NEW] The 4 arithmetic operators: +, -, *, and /.
const Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result = *this;
	result.val += other.val;
	return result;
}
const Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result = *this;
	result.val -= other.val;
	return result;
}
const Fixed Fixed::operator*(const Fixed &other) const {
	long long product = this->val * other.val;
	product = product >> Fixed::fract;
	Fixed result;
	result.val = (int(product));
	return result;
}
const Fixed Fixed::operator/(const Fixed &other) const {
	long long product = this->val / other.val;
	product = product >> Fixed::fract;
	Fixed result;
	result.val = (int(product));
	return result;
}

// [NEW] The 4 increment/decrement (pre-increment and post-increment, pre-decrement andpost-decrement) operators, that will increase or decrease the fixed-point value fromthe smallest representable ε such as 1 + ε > 1.
Fixed& Fixed::operator++() {
	this->val++;
	return *this;
}
Fixed& Fixed::operator--() {
	this->val--;
	return *this;
}
Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	++(*this);
	return tmp;
}
Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	--(*this);
	return tmp;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called." << std::endl;	
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

// [NEW] A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a.val > b.val ? a : b;
}
// [NEW] A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a.val > b.val ? a : b;
}
// [NEW] A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a.val > b.val ? a : b;
}
// [NEW] A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a.val > b.val ? a : b;
}
