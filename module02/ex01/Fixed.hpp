#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed {
private:
    // A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
    static const int fract = 8;
    // An integer to store the fixed-point number value.
    int val;
public:
    // A default constructor that initializes the fixed-point number value to 0.
    Fixed();
    // A copy constructor.
    Fixed(const Fixed&);
    // A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
    Fixed(const int input);
    // A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
    Fixed(const float input);
    // A destructor.
    ~Fixed();

    // A copy assignment operator overload.
    Fixed& operator=(const Fixed&);

    // A member function that returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // A member function that sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
    // A member function that converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;
    // A member function that converts the fixed-point value to an integer value.
    int toInt( void ) const;
};

// An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<( std::ostream& out, Fixed const& fixed);

#endif