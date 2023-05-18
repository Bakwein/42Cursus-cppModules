#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>
#include <fstream>

class Fixed
{
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