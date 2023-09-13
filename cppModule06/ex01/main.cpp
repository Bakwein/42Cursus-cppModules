#include "Data.hpp"

int main()
{
    Data *d = new Data; 
    std::cout << d << std::endl;
    d->s1 = "sefaT!";
    d->num = 41;
    std::cout << d << std::endl;

    std::cout << std::endl;
    uintptr_t ui = serialize(d);
    std::cout << ui << std::endl;
    Data *ptr = deserialize(ui);
    std::cout << std::endl;
    std::cout << ptr << std::endl;
    std::cout << "ptr->num: " << ptr->num << std::endl;
    std::cout << "ptr->s1: " << ptr->s1 << std::endl;
}