#include "fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed &original)
{  
    *this = original;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
    {
        this->fixedPointValue = other.fixedPointValue;
    }
    return (*this);
}

Fixed::Fixed(int param)
{
    this->fixedPointValue = param * 256;
}

Fixed::Fixed(float param)
{
    this->fixedPointValue = (int)roundf(param * 256);
}

int Fixed::getRawBits(void) const
{
    return (this->fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::toInt() const
{
    return (fixedPointValue / 256);
}

float Fixed::toFloat() const
{
    return (fixedPointValue / 256.0);
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

bool operator<(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() < fixed2.getRawBits());
}

bool operator>(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() > fixed2.getRawBits());
}

bool operator<=(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() <= fixed2.getRawBits());
}

bool operator>=(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() >= fixed2.getRawBits());
}

bool operator==(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() == fixed2.getRawBits());
}

bool operator!=(const Fixed& fixed1, const Fixed& fixed2)
{
    return (fixed1.getRawBits() != fixed2.getRawBits());
}

Fixed operator+(const Fixed& fixed1, const Fixed& fixed2)
{
    Fixed res;

    res.setRawBits(fixed1.getRawBits() + fixed2.getRawBits());
    return (res);
}

Fixed operator-(const Fixed& fixed1, const Fixed& fixed2)
{
    Fixed res;

    res.setRawBits(fixed1.getRawBits() - fixed2.getRawBits());
    return (res);
}

Fixed operator*(const Fixed& fixed1, const Fixed& fixed2)
{
    Fixed res;
    
    long temp;

    temp = fixed1.getRawBits() * fixed2.getRawBits();
    res.setRawBits(temp / (1 << 8));
    return (res);
}

Fixed operator/(const Fixed& fixed1, const Fixed& fixed2)
{
    Fixed res;
    
    long temp;

    temp = fixed1.getRawBits() * (1 << 8);
    res.setRawBits(temp / fixed2.getRawBits());
    return (res);
}

Fixed &Fixed::operator++()
{
    this->setRawBits((this->getRawBits() + 1));
    return (*this);
}

Fixed Fixed::operator++(int param)
{
    (void)param;
    Fixed temp(*this);
    ++(*this);
    return (temp);
}

Fixed &Fixed::operator--()
{
    this->setRawBits((this->getRawBits() - 1));
    return (*this);
}

Fixed Fixed::operator--(int param)
{
    (void)param;
    Fixed temp(*this);
    --(*this);
    return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return (a);
    return (b);
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return (a);
    return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return (a);
    return (b);
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return (a);
    return (b);
}