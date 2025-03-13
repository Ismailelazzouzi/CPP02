#include "fixed.hpp"

Fixed::Fixed() : fixedPointValue(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Deconstructor called" << std::endl;
}

Fixed::Fixed(const Fixed &original)
{  
    std::cout << "copy constructor called" << std::endl;
    *this = original;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->fixedPointValue = other.getRawBits();
    }
    return (*this);
}

Fixed::Fixed(int param)
{
    this->fixedPointValue = param * 256;
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float param)
{
    this->fixedPointValue = (int)roundf(param * 256);
    std::cout << "float constructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixedPointValue);
}
void Fixed::setRawBits(int const raw)
{
    this->fixedPointValue = raw;
}

int Fixed::toInt()
{
    return (fixedPointValue / 256);
}

float Fixed::toFloat()
{
    return (fixedPointValue / 256.0);
}
