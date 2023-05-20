/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 23:47:02 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:47:03 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/**
 * @brief 
 * 
 * @return int 
 */
int	main()
{
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));

	// {
	// 	Fixed	c(10);
	// 	Fixed	cSmall(5);

	// 	std::cout << "[1] -> " << (10 > 5) << std::flush << std::endl;
	// 	std::cout << "[2] -> " << (10 < 5) << std::flush << std::endl;
	// 	std::cout << "[3] -> " << (10 >= 5) << std::flush << std::endl;
	// 	std::cout << "[4] -> " << (10 <= 5) << std::flush << std::endl;
	// 	std::cout << "[5] -> " << (10 == 5) << std::flush << std::endl;
	// 	std::cout << "[6] -> " << (10 != 5) << std::flush << std::endl;
	// }
	// {
	// 	Fixed		c(10);
	// 	Fixed		cSmall(5);

	// 	std::cout << "c: " << c << std::endl;
	// 	std::cout << "cSmall: " << cSmall << std::endl;
	// 	std::cout << "cSmall + c: " << cSmall + c << std::endl;
	// 	std::cout << "cSmall - c: " << cSmall - c << std::endl;
	// 	std::cout << "cSmall * c: " << cSmall * c << std::endl;
	// 	std::cout << "cSmall / c: " << cSmall / c << std::endl;
	// }
	// {
	// 	// Fixed		c(10);
	// 	Fixed		cSmall(5);

	// 	// std::cout << "c: " << c << std::endl;
	// 	std::cout << "cSmall: " << cSmall << std::endl;
	// 	std::cout << "cSmall--: " << cSmall-- << std::endl;
	// 	std::cout << "cSmall: " << cSmall << std::endl;
	// 	std::cout << "--cSmall: " << --cSmall << std::endl;
	// }

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max(a, b) << std::endl;
	{
		// std::cout << "max:" << Fixed::max(a, b) << std::endl;
		// std::cout << "min:" << Fixed::min(a, b) << std::endl;
	}

	return (0);
}
// $> ./a.out
// 0
// 0.00390625
// 0.00390625
// 0.00390625
// 0.0078125
// 10.1016
// 10.1016