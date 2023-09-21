#include "iter.hpp"

template <typename T>
void print(T &a)
{
    std::cout << "Value: " << a << std::endl;
}

void isWrong(std::string &a)
{
    std::cout << a << " is wrong!" << std::endl;
}

template <typename T>
void abs_converter(T &x)
{
    if(x < 0)
    {
        std::cout << (x * -1) << std::endl;
    }
    else
        std::cout << x << std::endl;
}

int main()
{
    int dizi[6] = {-2,3,-52,-125,-142,42};
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),abs_converter);
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);
}