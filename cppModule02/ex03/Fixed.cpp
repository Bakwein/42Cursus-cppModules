/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:50:28 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:50:30 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief Construct a new Fixed::Fixed object
 * Default Constructor.
 */
Fixed::Fixed( void ) : _fixPoint(0)
{
	// std::cout << "Default constructor called" << std::flush << std::endl;
	// this->_fixPoint = 0;
}

Fixed::Fixed( const int numberInt ) : _fixPoint(numberInt << _fractBits)
{
	// std::cout << "Int constructor called" << std::flush << std::endl;
	// this->_fixPoint = numberInt;
}

Fixed::Fixed( const float numberFloat) : _fixPoint(std::roundf(
	numberFloat * (1 << _fractBits)))
{
	// std::cout << "Float constructor called" << std::flush << std::endl;
	// this->_fixPoint = numberFloat;
}

/**
 * @brief Copy Construct a new Fixed::Fixed object
 * Copy Constructor.
 * @link https://www.geeksforgeeks.org/copy-constructor-in-cpp/
 * @param old_class 
 */
Fixed::Fixed( const Fixed &old_class)
{
	// std::cout << "Copy constructor called" << std::flush << std::endl;
	*this = old_class;
	// this->_fixPoint = old_class._fixPoint;
}

/**
 * @brief Copy assignment a new Fixed::Fixed object
 * Copy assignment operator.
 * @link https://en.cppreference.com/w/cpp/language/copy_assignment
 * @param old_class 
 * @return Fixed& 
 */
Fixed	&Fixed::operator=( const Fixed &old_class )
{
	// std::cout << "Copy assignment operator called" << std::flush << std::endl;
	this->_fixPoint = old_class.getRawBits();
	// this->_fixPoint = old_class._fixPoint;
	return (*this);
}

/*_________________COMPARISON OPERATORS__________________*/
bool	Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}
/*_______________________________________________________*/

/*_________________ARITHMETIC OPERATORS__________________*/
Fixed	Fixed::operator+(const Fixed &rhs) const
{
	// this->toFloat() + rhs.toFloat();
	// return (*this);
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &rhs) const
{
	// this->toFloat() - rhs.toFloat();
	// return (*this);
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &rhs) const
{
	// this->toFloat() * rhs.toFloat();
	// return (*this);
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &rhs) const
{
	// this->toFloat() / rhs.toFloat();
	// return (*this);
	return (Fixed(this->toFloat() / rhs.toFloat()));
}
/*_______________________________________________________*/

/*_____________INCREMENT/DECREMENT OPERATORS_____________*/
/*
	increment/decrement -> (artis/azalma)
	[pre-increment/pre-decrement] -> (ön artis/ön azalma)left(sol)
	[post-increment/post-decrement] -> (artis sonrasi/azalma sonrasi)right(sag)
*/
Fixed	Fixed::operator++( void )// Pre-increment -> ++Left
{
	this->_fixPoint++;
	return (*this);
}

Fixed	Fixed::operator++( int )// Post-increment -> Right++
{
	Fixed	tmp(*this);
	tmp._fixPoint = this->_fixPoint++;
	return (tmp);
	// return (Fixed(this->_fixPoint++));
}

Fixed	Fixed::operator--( void )// Pre-decrement -> --Left
{
	this->_fixPoint--;
	return (*this);
}

Fixed	Fixed::operator--( int )// Post-decrement -> Right--
{
	Fixed	tmp(*this);
	tmp._fixPoint = this->_fixPoint--;
	return (tmp);
	// return (Fixed(this->_fixPoint--));
}
/*_______________________________________________________*/

/**
 * @brief Destroy the Fixed::Fixed object
 * Destructor operator.
 */
Fixed::~Fixed( void )
{
	// std::cout << "Destructor called" << std::flush << std::endl;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::flush << std::endl;
	return (this->_fixPoint);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::flush << std::endl;
	this->_fixPoint = raw;
}

float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(this->getRawBits()) / (1 << _fractBits));
}

int	Fixed::toInt( void ) const
{
	return (this->getRawBits() >> _fractBits);
}

Fixed	&Fixed::min( Fixed &lhs, Fixed &rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}
const Fixed	&Fixed::min( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs.getRawBits() < rhs.getRawBits())
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::max( Fixed &lhs, Fixed &rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::max( const Fixed &lhs, const Fixed &rhs )
{
	if (lhs.getRawBits() > rhs.getRawBits())
		return (lhs);
	return (rhs);
}

std::ostream	&operator<<(std::ostream &foo, Fixed const &bar )
{
	foo << bar.toFloat();
	return (foo);
}