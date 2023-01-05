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
    Fixed(const int input);
    Fixed(const float input);
    ~Fixed();

    Fixed& operator=(const Fixed&);
    // [NEW] The 6 comparison operators: >, <, >=, <=, == and !=.
    bool operator>(const Fixed &other) const;
    bool operator<(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;
    // [NEW] The 4 arithmetic operators: +, -, *, and /.
    const Fixed operator+(const Fixed &other) const;
    const Fixed operator-(const Fixed &other) const;
    const Fixed operator*(const Fixed &other) const;
    const Fixed operator/(const Fixed &other) const;
    // [NEW] The 4 increment/decrement (pre-increment and post-increment, pre-decrement andpost-decrement) operators, that will increase or decrease the fixed-point value fromthe smallest representable ε such as 1 + ε > 1.
    Fixed& operator++();
    Fixed& operator--();
    Fixed operator++(int);
    Fixed operator--(int);

    int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    // [NEW] A static member function min that takes as parameters two references on fixed-point numbers, and returns a reference to the smallest one.
    static Fixed& min(Fixed& a, Fixed& b);
    // [NEW] A static member function min that takes as parameters two references to constant fixed-point numbers, and returns a reference to the smallest one.
    static const Fixed& min(const Fixed& a, const Fixed& b);
    // [NEW] A static member function max that takes as parameters two references on fixed-point numbers, and returns a reference to the greatest one.
    static Fixed& max(Fixed& a, Fixed& b);
    // [NEW] A static member function max that takes as parameters two references to constant fixed-point numbers, and returns a reference to the greatest one.
    static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream & operator<<( std::ostream& out, Fixed const& fixed);

#endif