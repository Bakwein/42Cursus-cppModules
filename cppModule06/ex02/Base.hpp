#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <ctime> // for creating random num
//srand(time(0)); rand();

# define BLACK        "\033[0;30m"
# define RED        "\033[0;31m"
# define GREEN        "\033[0;32m"
# define YELLOW        "\033[0;33m"
# define BLUE        "\033[0;34m"
# define PURPLE        "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE        "\033[0;37m"
# define END        "\033[m"
# define RESET        "\033[0m"
# define B_CYAN         "\033[1;36m"
# define B_BLUE         "\033[1;34m"
# define B_YELLOW     "\033[1;33m"
# define B_GREEN         "\033[1;32m"
# define B_RED         "\033[1;31m"
# define B_RESET         "\033[1m"

class Base
{
    public:
        virtual ~Base(void);
};


Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base* makeA(void);
Base* makeB(void);
Base* makeC(void);

#endif