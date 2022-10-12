#include "Fixed.hpp"

Fixed::Fixed(): val(0) {
}

Fixed::Fixed(const Fixed& orig): val(orig.val) {
}

Fixed& Fixed::operator=(const Fixed&){

}

Fixed::~Fixed(){

}

int Fixed::getRawBits( void ) const{

}

void Fixed::setRawBits( int const raw ){

}

