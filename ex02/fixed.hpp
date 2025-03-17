#include <iostream>
#include <cmath>

#pragma once

class Fixed
{
private:
    int fixedPointValue;
    static const int fractionalBits = 8;
public:
    Fixed();
    ~Fixed();
    Fixed(const Fixed &original);
    Fixed &operator=(const Fixed &other);
    Fixed(int param);
    Fixed(float param);
    int getRawBits(void) const;
    void setRawBits(int const raw);
    int toInt() const;
    float toFloat() const;
    Fixed &operator++();
    Fixed operator++(int param);
    Fixed &operator--();
    Fixed operator--(int param);
    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);
bool operator<(const Fixed& fixed1, const Fixed& fixed2);
bool operator>(const Fixed& fixed1, const Fixed& fixed2);
bool operator<=(const Fixed& fixed1, const Fixed& fixed2);
bool operator>=(const Fixed& fixed1, const Fixed& fixed2);
bool operator==(const Fixed& fixed1, const Fixed& fixed2);
bool operator!=(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator+(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator-(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator*(const Fixed& fixed1, const Fixed& fixed2);
Fixed operator/(const Fixed& fixed1, const Fixed& fixed2);