#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>

class Fixed {
private:
    static const int fract = 8;
    int val;
public:
    Fixed();
    Fixed(const Fixed&);

    // [NEW] A constructor that takes a constant integer as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
    Fixed(const int input);
    // [NEW] A constructor that takes a constant floating-point number as a parameter. It converts it to the corresponding fixed-point value. The fractional bits value is initialized to 8 like in exercise 00.
    Fixed(const float input);

    ~Fixed();

    Fixed& operator=(const Fixed&);

    int getRawBits( void ) const;
    void setRawBits( int const raw );

    // [NEW] A member function that converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;
    // [NEW] A member function that converts the fixed-point value to an integer value.
    int toInt( void ) const;
};

// [NEW] An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<( std::ostream& out, Fixed const& fixed);

#endif