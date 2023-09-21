#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

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

//using namespace std;

/**
 * @brief heyoooo!!!
 * 
 * @tparam T 
 * @param a 
 * @param b 
 */
template <typename T>
void swap(T &a,T &b)
{
    //std::cout << YELLOW << "Swap!" << RESET << std::endl;
    T temp  = a;
    a = b;
    b = temp;
}

template <typename T>
T min(T a,T b) //equal => second par
{
    //std::cout << RED << "Min!" << RESET << std::endl;
    /*
    if(a < b)
        return a;
    else 
        return b;
    */

    return (a < b) ? a : b;

}

template <typename S>
S max(S a,S b) //equal => second par
{
    //std::cout << CYAN << "Max!" << RESET << std::endl;
    /*
    if(a > b)
        return a;
    else 
        return b;
    */

   return(a>b) ? a:b;
}
#endif