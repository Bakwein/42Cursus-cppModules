/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:17:51 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 15:14:33 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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

};

#endif