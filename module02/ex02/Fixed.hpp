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
    // The 6 comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    // The 4 arithmetic operators: +, -, *, and /.
    const Fixed operator+(const Fixed &other) const;
    const Fixed operator-(const Fixed &other) const;
    const Fixed operator*(const Fixed &other) const;
    const Fixed operator/(const Fixed &other) const;
    // The 4 increment/decrement (pre-increment and post-increment, pre-decrement andpost-decrement) operators, that will increase or decrease the fixed-point value fromthe smallest representable ε such as 1 + ε > 1.
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    // A member function that returns the raw value of the fixed-point value.
    int getRawBits( void ) const;
    // A member function that sets the raw value of the fixed-point number.
    void setRawBits( int const raw );
    // A member function that converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;
    // A member function that converts the fixed-point value to an integer value.
    int toInt( void ) const;

    // A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
    static Fixed& min(Fixed& a, Fixed& b);
    // A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
    static const Fixed& min(const Fixed& a, const Fixed& b);
    // A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
    static Fixed& max(Fixed& a, Fixed& b);
    // A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

// An overload of the insertion («) operator that inserts a floating-point representation of the fixed-point number into the output stream object passed as parameter.
std::ostream & operator<<( std::ostream& out, Fixed const& fixed);

#endif