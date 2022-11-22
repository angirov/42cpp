#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
	// std::cout << "Fixed object default constructor is called." << std::endl;
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
	std::cout << "Fixed object copy constructor is called." << std::endl;
}

Fixed::Fixed(const int input): val(input << 8) {};

Fixed::Fixed(const float input): val(round(input * (1 << 8))) {};

Fixed& Fixed::operator=(const Fixed& orig) {
	this->val = orig.val;
	return *this;
}

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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a.val > b.val ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a.val > b.val ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a.val > b.val ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a.val > b.val ? a : b;
}

Fixed::~Fixed() {
	std::cout << "Fixed object destructor is called." << std::endl;
}
