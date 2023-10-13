#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>


template<typename T>
void    easyfind(T a,int i)
{
    if(a.empty())
    {
        std::cout << "container is empty!" << std::endl;
        return;
    }
    if(std::find(a.begin(),a.end(),i) != a.end())
    {
        std::cout << "container has " << i << " value!" << std::endl;
    }    
    else
    {
        std::cout << i << " not found!" << std::endl;
    }
}

#endif