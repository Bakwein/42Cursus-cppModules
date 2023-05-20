/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:50:24 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:50:25 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed num)
{
	if (num < 0)
		return (num * -1);// We don't have *= operator :').
	return (num);
}

static Fixed	area( Point const a, Point const b, Point const c)
{
	return (abs(((a.getPointX() * (b.getPointY() - c.getPointY()))
		+ (b.getPointX() * (c.getPointY() - a.getPointY()))
		+ (c.getPointX() * (a.getPointY() - b.getPointY()))) / 2));
}

/**
 * @brief 
 * 
Input: A = (0, 0), B = (4, 3), C = (4, 0), P(3, 1)
Output: Inside
Explanation:
              B(4,3)
                / \
               /   \
              /     \
             /   P   \      P'
            /         \
     A(0,0) ----------- C(4,0)

Input: A = (0, 0), B = (4, 3), C = (4, 0), P(3, 1)
Output: Outside
Explanation:
              B(4,3)
                / \
               /   \
              /     \
             /       \      P
            /         \
     A(0,0) ----------- C(4,0)

Solution: 
Let the coordinates of three corners be (x1, y1), (x2, y2) and (x3, y3). And coordinates of the given point P be (x, y)

Calculate area of the given triangle, i.e., area of the triangle ABC in the above diagram.
Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1 - y2) ] / 2
Calculate area of the triangle PAB. We can use the same formula for this. Let this area be A1.
Calculate area of the triangle PBC. Let this area be A2.
Calculate area of the triangle PAC. Let this area be A3.
If P lies inside the triangle, then A1 + A2 + A3 must be equal to A.
 * 
 * @param a 
 * @param b 
 * @param c 
 * @param point 
 * @link https://www.geeksforgeeks.org/check-whether-a-given-point-lies-inside-a-triangle-or-not/
 * @return true If point inside.
 * @return false If point outside.
 */
bool	bspArea( Point const a, Point const b, Point const c, Point const point )
{
	if ((point.getPointX() == a.getPointX()
		&& point.getPointY() == a.getPointY()))
	{
		std::cout << RED "Point on 'a' vertex!" END << std::flush << std::endl;
		return (false);
	}
	else if ((point.getPointX() == b.getPointX()
		&& point.getPointY() == b.getPointY()))
	{
		std::cout << RED "Point on 'b' vertex!" END << std::flush << std::endl;
		return (false);
	}
	else if ((point.getPointX() == c.getPointX()
		&& point.getPointY() == c.getPointY()))
	{
		std::cout << RED "Point on 'c' vertex!" END << std::flush << std::endl;
		return (false);
	}
	Fixed	abcArea = area(a, b, c);
	Fixed	pabArea = area(point, a, b);
	Fixed	pbcArea = area(point, b, c);
	Fixed	pcaArea = area(point, c, a);

	std::cout << "pointX: " << point.getPointX() << std::endl;
	std::cout << "pointY: " << point.getPointY() << std::endl;
	std::cout << "abc: " << abcArea << std::endl;
	std::cout << "pab: " << pabArea << std::endl;
	std::cout << "pbc: " << pbcArea << std::endl;
	std::cout << "pca: " << pcaArea << std::endl;

	return ((pabArea + pbcArea + pcaArea) == abcArea);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	if ((point.getPointX() == a.getPointX()
		&& point.getPointY() == a.getPointY()))
	{
		std::cout << RED "Point on 'a' vertex!" END << std::flush << std::endl;
		return (false);
	}
	else if ((point.getPointX() == b.getPointX()
		&& point.getPointY() == b.getPointY()))
	{
		std::cout << RED "Point on 'b' vertex!" END << std::flush << std::endl;
		return (false);
	}
	else if ((point.getPointX() == c.getPointX()
		&& point.getPointY() == c.getPointY()))
	{
		std::cout << RED "Point on 'c' vertex!" END << std::flush << std::endl;
		return (false);
	}
	Fixed	bx(b.getPointX() - a.getPointX());
	Fixed	by(b.getPointY() - a.getPointY());
	Fixed	cx(c.getPointX() - a.getPointX());
	Fixed	cy(c.getPointY() - a.getPointY());
	Fixed	x(point.getPointX() - a.getPointX());
	Fixed	y(point.getPointY() - a.getPointY());
	Fixed	d(bx * cy - cx * by);

	Fixed	WA = (x * (by - cy) + y * (cx - bx) + bx * cy - cx * by) / d;
	Fixed	WB = (x * cy - y * cx) / d;
	Fixed	WC = (y * bx - x * by) / d;

	std::cout << "bx: " << bx << std::flush << std::endl;
	std::cout << "by: " << by << std::flush << std::endl;
	std::cout << "cx: " << cx << std::flush << std::endl;
	std::cout << "cy: " << cy << std::flush << std::endl;
	std::cout << "x: " << x << std::flush << std::endl;
	std::cout << "y: " << y << std::flush << std::endl;
	std::cout << "d: " << d << std::flush << std::endl;
	std::cout << "WA: " << WA << std::flush << std::endl;
	std::cout << "WB: " << WB << std::flush << std::endl;
	std::cout << "WC: " << WC << std::flush << std::endl;

	if (!(WA.toFloat() >= 0.0 && WA.toFloat() <= 1.0))
		return (false);
	else if (!(WB.toFloat() >= 0.0 && WB.toFloat() <= 1.0))
		return (false);
	else if (!(WC.toFloat() >= 0.0 && WC.toFloat() <= 1.0))
		return (false);
	return (true);
}
