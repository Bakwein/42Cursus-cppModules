#include "iter.hpp"

template <typename T>
void print(T &a)
{
    std::cout << a << " ";
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
        //x = x * -1;
        std::cout << (x * -1) << " ";
    }
    else
        std::cout << x << " ";
}

template <typename X>
int increase_and_return(X &a)
{
    a = a+1;
    return(a);
}

int main()
{
    int dizi[6] = {-2,3,-52,-125,-142,42};
    std::cout << "Before:";
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);
    std::cout << std::endl;
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),abs_converter);
    std::cout << std::endl;
    std::cout << "After:";
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);

    std::cout << "\n\n";

    std::cout << "Before increase:";
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);
    std::cout << std::endl;
    iter2(dizi,sizeof(dizi)/sizeof(dizi[0]),increase_and_return);
    std::cout << std::endl;
    std::cout << "After increase:";
    iter(dizi,sizeof(dizi)/sizeof(dizi[0]),print);


}