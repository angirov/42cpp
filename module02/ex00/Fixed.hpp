#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

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
    // A copy assignment operator overload.
    Fixed& operator=(const Fixed&);
    // A destructor.
    ~Fixed();
    // A member function that returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // A member function that sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
};

#endif