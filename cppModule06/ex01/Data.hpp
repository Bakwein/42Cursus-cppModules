#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <string>

struct Data
{
    std::string s1;
    int num;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif