#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed const c( Fixed( 5.05f ) );
    Fixed const d( Fixed( 2 ) );
    std::cout << "a:\t\t" << a << std::endl;
    std::cout << "++a:\t\t" << ++a << std::endl;
    std::cout << "a:\t\t" << a << std::endl;
    std::cout << "a++\t\t" << a++ << std::endl;
    std::cout << "a\t\t" << a << std::endl;

    std::cout << "b:\t\t" << b << std::endl;
    std::cout << "max(a, b):\t\t" << Fixed::max( a, b ) << std::endl;
    // std::cout << "c:\t\t" << c << std::endl;
    // std::cout << "d:\t\t" << d << std::endl;
    // std::cout << "c*d:\t\t" << c*d << std::endl;
    return 0;
}

// http://courses.cms.caltech.edu/cs11/material/cpp/donnie/cpp-ops.html