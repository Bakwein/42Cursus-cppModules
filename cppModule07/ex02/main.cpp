#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0; 
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    
    return 0;

    /*
    {
        try
        {
            int num1 = (rand() % 8)+1;
            int num2 = (rand() % 5)+1;

            Array<int> a(num1);
            Array<int> b(num2);
            std::cout << "a size: " << a.size() << std::endl;
            std::cout << "b size: " << b.size() << std::endl;


            std::cout << BLUE << "-------------------------------" <<   RESET     << std::endl;

            std::cout << B_RED << "a:" << RESET ;
            for(unsigned int i = 0; i < a.size();i++)
            {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;

            std::cout << B_YELLOW <<"b:"<<RESET;
            for(unsigned int i = 0; i < b.size();i++)
            {
                std::cout << b[i] << " ";
            }

            std::cout << std::endl;
            std::cout << BLUE << "-------------------------------" <<   RESET     << std::endl;

            std::cout << YELLOW "a was created" << RESET << std::endl;
            for(unsigned int i = 0; i < a.size();i++)
            {
                //std::cout << i << std::endl;
                a[i] = rand() % 1000;
                int flag1 = rand() % 2;
                if(flag1)
                    a[i] = a[i] * -1;
            }

            std::cout <<YELLOW <<  "b was created!" << RESET <<     std::endl;
            for(unsigned int i = 0; i < b.size();i++)
            {
                b[i] = rand() % 1000;
                int flag2 = rand() % 2;
                if(flag2)
                    b[i] = b[i] * -1;
            }
            std::cout << BLUE << "-------------------------------" <<   RESET     << std::endl;
            std::cout << B_RED << "a:";
            for(unsigned int i = 0; i < a.size();i++)
            {
                std::cout << a[i] << " ";
            }
            std::cout << std::endl;
            std::cout << B_YELLOW <<  "b:";
            for(unsigned int i = 0; i < b.size();i++)
            {
                std::cout << b[i] << " ";
            }
            std::cout << "\n\n";
        }
        catch(const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }

    }
    std::cout << PURPLE << "-------------------------------" <<   RESET     << std::endl;
   
    {
        try
        {
            Array<char> b(1);
            b[0] = 90;
            std::cout << "b[0]:" << b[0] << std::endl;
            b[1905] = 'x';
        }
        catch(const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << PURPLE << "-------------------------------" <<   RESET     << std::endl;
    {
        try
        {
            Array<int> a1(0);
            std::cout << a1[0] << std::endl;
        }
        catch(const std::exception &e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    */
}