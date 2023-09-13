#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <ctime> // for creating random num
//srand(time(0)); rand();
/*

*/
class Base
{
    public:
        virtual ~Base(void);
};
/*
class A : public Base
{
};

class B : public Base
{
};

class C : public Base 
{
};
*/

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base* makeA(void);
Base* makeB(void);
Base* makeC(void);

#endif