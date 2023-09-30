#include <iostream>

int main()
{
    int id=65;
    int *ip;

    ip = &id;

    // Farklı veri türünde işaretçiler arasında dönüşüm
    char *cp = reinterpret_cast<char*>(ip);
    std::cout << *cp << "\n";
    
    // Bir veri türünü aynı veri türünden bir işaretçiye dönüştürme
    int *ip2 = reinterpret_cast<int*>(id);
    std::cout << ip2 << "\n";
    
    // Bir işaretçiden bir veri türüne dönüşüm
    long int lid = reinterpret_cast<long>(ip2);
    std::cout << lid << "\n";

    



}