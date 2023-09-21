#include "whatever.hpp"

int main()
{
    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b <<        std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b )      << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b )      << std::endl;
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d <<        std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d )      << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d )      << std::endl;
    }
    std::cout << PURPLE <<    "--------------------------- " << RESET <<     std::endl;

    {
        int a = 4;
        int b = -3;
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;
        swap(a,b);
        //::swap(a,b);
        std::cout << "a: " << a << std::endl;
        std::cout << "b: " << b << std::endl;

        std::cout << min(a,b) << std::endl;
        std::cout << max(a,b) << std::endl;

        std::cout << BLUE <<    "--------------------------- " << RESET <<     std::endl;

        float f1 = 124.24124;
        float f2 = -124124.125125;

        std::cout << "f1: " << f1 << std::endl;
        std::cout << "f2: " << f2 << std::endl;
        swap(f1,f2);
        //::swap(f1,f2);
        std::cout << "f1: " << f1 << std::endl;
        std::cout << "f2: " << f2 << std::endl;

        std::cout << min(f1,f2) << std::endl;
        std::cout << max(f1,f2) << std::endl; 

        std::cout << BLUE <<    "--------------------------- " << RESET <<     std::endl;

        char ch1 = 'z';
        char ch2 = 'Z';

        std::cout << "ch1: " << ch1 << " " << "ch2:     " << ch2 << std::endl;
        swap(ch1,ch2);
        std::cout << "ch1: " << ch1 << " " << "ch2:     " << ch2 << std::endl;
        std::cout << "\n";
        std::cout << "int("<< ch1 << "): " << int   (ch1) << std::endl;
        std::cout << "int(" << ch2 << "): "  << int (ch2) << std::endl;
        std::cout << min(ch1,ch2) << std::endl;
        std::cout << max(ch1,ch2) << std::endl;
    }

    return 0;
}