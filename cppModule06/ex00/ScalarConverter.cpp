#include "ScalarConverter.hpp"

int ScalarConverter::atoi(std::string av)
{
    int num = 0;
    int neg_flag = 0;
    int a = 0;
    int len = av.length();
    int temp = 0;

    while(av[a] < 32)
    {
        a++;
    }
    temp = a;
    while((av[a] >= 'a' && av[a] <= 'z') ||(av[a] >= 'A' && av[a] <= 'Z'))
    {
        a++;
    }
    a = temp;
    if(av[a] == '+' || av[a] == '-')
    {
        if(av[a] == '-')
        {
            neg_flag = -1;
        }
        a++;
    }
    while(av[a] >= '0' && av[a] <= '9')
    {
        num = 10 * num + (av[a]-'0');
        a++;
    }
    if(a != len)
    {
        return (-1);
    }



    //degisecek
    return num * neg_flag;
}