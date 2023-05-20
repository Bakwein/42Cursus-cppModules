/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:50:54 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:50:55 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::flush << std::endl;
}

Point::Point( const float x, const float y) : _x(x), _y(y)
{
	// std::cout << "2 param constructor called" << std::flush << std::endl;
}

Point::Point( const Point &rhs ) : _x(rhs._x), _y(rhs._y)
{
	// std::cout << "Copy constructor called" << std::flush << std::endl;
}

Point::~Point( void )
{
	// std::cout << "Destructor called" << std::flush << std::endl;
}

Point	&Point::operator=( const Point &rhs )
{
	// std::cout << "Copy assignment operator called" << std::flush << std::endl;
	if (this != &rhs)
	{
		// const_cast< Fixed& > (this->_x) = rhs.getPointX();
		// const_cast< Fixed& > (this->_y) = rhs.getPointY();
		(Fixed)this->_x = rhs.getPointX();
		(Fixed)this->_y = rhs.getPointY();
	}
	return (*this);
}

Fixed	Point::getPointX( void ) const
{
	return (this->_x);
}
Fixed	Point::getPointY( void ) const
{
	return (this->_y);
}

// std::ostream	&operator<<(std::ostream &lhs, Point &rhs)
// {
	
// }