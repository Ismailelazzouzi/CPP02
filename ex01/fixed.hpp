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
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);