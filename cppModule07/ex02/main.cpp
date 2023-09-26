#include "Array.hpp"

int main()
{
    Array<int> a(5);
    Array<int> b(2);
    b = a;

    

    std::cout << "a:";
    for(unsigned int i = 0; i < a.getSize();i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "b:";
    for(unsigned int i = 0; i < b.getSize();i++)
    {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
}