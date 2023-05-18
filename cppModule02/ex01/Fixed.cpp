#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixPoint = 0;
}

Fixed::Fixed(const Fixed &old)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixPoint = old.getRawBits();
}

Fixed::Fixed(const int intNum) : fixPoint(intNum << fractBit)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float floatNum) : fixPoint(std::roundf(floatNum * (1 << fractBit)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &old)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixPoint = old.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixPoint);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixPoint = raw;
}

float Fixed::toFloat(void)const
{
    return(static_cast<float>(this->getRawBits())) / (1 << fractBit);
}

int Fixed::toInt(void)const
{
    return (this->getRawBits() >> fractBit);
}

std::ostream &operator<<(std::ostream &foo, Fixed const &bar)
{
    foo << bar.toFloat();
    return (foo);
}