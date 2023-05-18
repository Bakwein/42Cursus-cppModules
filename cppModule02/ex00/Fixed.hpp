#ifndef FIXED_H
#define FIXED_H

#include <iostream>

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

};

#endif