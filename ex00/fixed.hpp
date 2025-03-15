#include <iostream>

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
    int getRawBits(void) const;
    void setRawBits(int const raw);
};

