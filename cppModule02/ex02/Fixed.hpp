/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:46:39 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:46:40 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>// just roundf() allowed.
#include <fstream>

/**
 * @brief 
 * 
 * LHS -> Left Hand Side
 * RHS -> Right Hand Side
 * 
 * OPERATORS:
 * @link https://en.cppreference.com/w/cpp/language/operators
 * 
 * COMPARISON:
 * @link https://en.cppreference.com/w/cpp/language/operator_comparison
 * ARITHMETIC:
 * @link https://en.cppreference.com/w/cpp/language/operator_arithmetic
 * INCREMENT: DECREMENT:
 * @link https://learn.microsoft.com/tr-tr/cpp/cpp/increment-and-decrement-operator-overloading-cpp?view=msvc-170
 * @link https://en.cppreference.com/w/cpp/language/operator_incdec
 */
class	Fixed
{
	private:
		int					_fixPoint;
		static const int	_fractBits = 8;
	public:
		Fixed( void );
		Fixed( const int numberInt);
		Fixed( const float numberFloat );
		Fixed( const Fixed &old_class );
		Fixed	&operator=( const Fixed &old_class );
		~Fixed( void );
/*_________________COMPARISON OPERATORS__________________*/
		bool	operator>( const Fixed &rhs ) const;
		bool	operator<( const Fixed &rhs ) const;
		bool	operator>=( const Fixed &rhs ) const;
		bool	operator<=( const Fixed &rhs ) const;
		bool	operator==( const Fixed &rhs ) const;
		bool	operator!=( const Fixed &rhs ) const;
/*_______________________________________________________*/

/*_________________ARITHMETIC OPERATORS__________________*/
		Fixed	operator+( const Fixed &rhs ) const;
		Fixed	operator-( const Fixed &rhs ) const;
		Fixed	operator*( const Fixed &rhs ) const;
		Fixed	operator/( const Fixed &rhs ) const;
/*_______________________________________________________*/

/*_____________INCREMENT/DECREMENT OPERATORS_____________*/
		Fixed	operator++( void );// Prefix increment operator.
		Fixed	operator++( int );// Postfix increment operator.
		Fixed	operator--( void );// Prefix decrement operator.
		Fixed	operator--( int );// Postfix decrement operator.
/*_______________________________________________________*/

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

		float	toFloat( void ) const;
		int		toInt( void ) const;

		static Fixed		&min( Fixed &lhs, Fixed &rhs );
		static const Fixed	&min( const Fixed &lhs, const Fixed &rhs );
		static Fixed		&max( Fixed &lhs, Fixed &rhs );
		static const Fixed	&max( const Fixed &lhs, const Fixed &rhs );
};

std::ostream	&operator<<(std::ostream &foo, Fixed const &bar);

#endif