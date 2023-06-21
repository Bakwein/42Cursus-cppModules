/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:17:26 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 13:17:28 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <fstream>

class Fixed
{
    private:
        int fixPoint;
        static const int fractBit = 8;
    public:
        Fixed();
        Fixed(const Fixed &);
        Fixed &operator=(const Fixed &);
        ~Fixed();
        int getRawBits(void)const;
        void setRawBits(int const raw);

        Fixed(const int);
        Fixed(const float);
        float toFloat(void)const;
        int toInt(void)const;

};

std::ostream &operator<<(std::ostream &o, const Fixed &);

#endif