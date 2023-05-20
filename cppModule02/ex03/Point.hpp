/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:50:59 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:53:09 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define BLACK		"\033[0;30m"
# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define PURPLE		"\033[0;35m"
# define CYAN		"\033[0;36m"
# define WHITE		"\033[0;37m"
# define END		"\033[m"
# define RESET		"\033[0m"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
		// Anything else useful etc. -> double sample;
	public:
		Point( void );
		Point( const float x, const float y);
		Point( const Point &rhs );
		~Point( void );
		Point &operator=( const Point &rhs );

		Fixed	getPointX( void ) const;
		Fixed	getPointY( void ) const;
};

bool	bspArea( Point const a, Point const b, Point const c, Point const point );
bool	bsp( Point const a, Point const b, Point const c, Point const point );

// std::ostream	&operator<<( std::ostream &lhs, Point const &rhs );

#endif // POINT_HPP