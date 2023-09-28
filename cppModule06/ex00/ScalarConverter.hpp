#ifndef SCALAR_H
#define SCALAR_H

#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <float.h>
#include <exception>


# define BLACK        "\033[0;30m"
# define RED        "\033[0;31m"
# define GREEN        "\033[0;32m"
# define YELLOW        "\033[0;33m"
# define BLUE        "\033[0;34m"
# define PURPLE        "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE        "\033[0;37m"
# define END        "\033[m"
# define RESET        "\033[0m"
# define B_CYAN         "\033[1;36m"
# define B_BLUE         "\033[1;34m"
# define B_YELLOW     "\033[1;33m"
# define B_GREEN         "\033[1;32m"
# define B_RED         "\033[1;31m"
# define B_RESET         "\033[1m"

/*
In C++, there is no special syntax or keyword to define a class as static.
Instead, a class can be considered a static class
 if it meets the following conditions:

All members are static: A static class should only contain static members,
 since non-static members would require an instance of the class to be created.

No instances can be created: Since a static class is never instantiated,
 it should not have any public constructors.
 It can have a private constructor or no constructor at all.

No inheritance: A static class cannot be inherited from, since it does not
 have any instances to inherit from.

Namespace scope: A static class should be defined at namespace scope,
 rather than as a member of another class.

Here is an example of a static class that meets these conditions:

namespace MyNamespace {
    class MyStaticClass {
    public:
        static int myStaticMethod() {
            return 42;
        }

        // Other static members...
    };

    // Define static members outside of the class definition
    int MyStaticClass::myStaticMethod() {
        return 42;
    }
}

In this example, MyStaticClass has only static members and cannot be instantiated.
It is defined at namespace scope and does not allow inheritance.
*/

/*
There is no such thing as a static class in C++. The closest approximation is a class that only contains static data members and static methods.

Static data members in a class are shared by all the class objects as there is only one copy of them in the memory, regardless of the number of objects of the class. Static methods in a class can only access static data members, other static methods or any methods outside the class.
*/

/*
char
• int
• float
• double
*/

class ScalarConverter
{
    private:
        //
    public:
    
        static void convert(std::string &str);

        static int isChar(std::string &str);
        static int isFloat(std::string &str);
        static int isDouble(std::string &str);
        static int isInt(std::string &str);
        static int control(std::string &str);
        static int dif(std::string &str);

        template <typename T>
        static void printChar(T charValue)
        {
            std::cout << "char: ";
            if((charValue>= 32 && charValue <=47) || (charValue >= 58 && charValue <= 126))
                std::cout << "'" << static_cast<char>(charValue) << "'" << std::endl;
            else if(charValue < 32 || charValue > 126 || (charValue >= 48 && charValue <= 57))
            {
                std::cout << "Non displayable" << std::endl;
            }
            else
            {
                std::cout << "impossible" << std::endl;
            }
        }

        template <typename T>
        static void printInt(T intValue)
        {
            std::cout << "int: ";
            if(intValue >= INT_MIN && intValue <= INT_MAX)
                std::cout << static_cast<int>(intValue) << std::endl;
            else
                std::cout << "impossible" << std::endl;
        }

        template <typename T>
        static void printFloat(T floatValue)
        {
            std::cout << "float: ";
            floatValue = static_cast<float>(floatValue);
            if(floatValue - int(floatValue) == 0)
                std::cout << floatValue << ".0f" << std::endl;
            else
                std::cout << floatValue << "f" << std::endl;
        }

        template <typename T>
        static void printDouble(T doubleValue)
        {
            std::cout << "double: ";
            doubleValue = static_cast<double>(doubleValue);
            if(doubleValue - int(doubleValue) == 0)
                std::cout << doubleValue << ".0" << std::endl;
            else
                std::cout << doubleValue << std::endl;
            
        }


        /*class intCastError : std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return("int cast error!");
                }
        };

        class doubleCastError : std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return("double cast error!");
                }
        };

        class floatCastError : std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return("float cast error!");
                }
        };

        class charCastError : std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return("char cast error!");
                }
        };
*/
};

#endif

/*
Write a static class ScalarConverter that will contain a method "convert" takes as
parameter a string representation of a C++ literal in its most common form. This literal
must belong to one of the following a scalar types:
• char
• int
• float
• double
Except for char parameters, only the decimal notation will be used.
Examples of char literals: ’c’, ’a’, ...
To make things simple, please note that non displayable characters shouldn’t be used as
inputs. If a conversion to char is not displayable, prints an informative message.
Examples of int literals: 0, -42, 42...
Examples of float literals: 0.0f, -4.2f, 4.2f...
You have to handle these pseudo literals as well (you know, for science): -inff, +inff
and nanf.
6
C++ - Module 06 C++ casts
Examples of double literals: 0.0, -4.2, 4.2...
You have to handle these pseudo literals as well (you know, for fun): -inf, +inf and nan.
7
C++ - Module 06 C++ casts
Write a program to test that your class works as expected.
You have to first detect the type of the literal passed as parameter, convert it from
string to its actual type, then convert it explicitly to the three other data types. Lastly,
display the results as shown below.
If a conversion does not make any sense or overflows, display a message to inform
the user that the type conversion is impossible. Include any header you need in order to
handle numeric limits and special values





"Dönüştürme"nin şu şekilde alacağı yöntemi içerecek statik bir ScalarConverter sınıfı yazın:
parametre, bir C++ değişmezinin en yaygın biçimindeki dize temsilidir. Bu gerçek
aşağıdaki a skaler türlerinden birine ait olmalıdır:
• karakter
• dahili
• batmadan yüzmek
• çift
Char parametreleri dışında yalnızca ondalık gösterim kullanılacaktır.
Karakter değişmezlerine örnekler: 'c', 'a', ...
İşleri basitleştirmek için lütfen görüntülenemeyen karakterlerin kullanılmaması gerektiğini unutmayın.
girişler. Karaktere dönüştürme görüntülenemiyorsa bilgilendirici bir mesaj yazdırır.
İnt değişmez değerlerine örnekler: 0, -42, 42...
Float değişmez değerlerine örnekler: 0.0f, -4.2f, 4.2f...
Bu sözde değişmezleri de ele almalısınız (biliyorsunuz, bilim için): -inff, +inff
ve nanf.
6
C++ - Modül 06 C++ yayınları
Çift değişmez değerlere örnekler: 0,0, -4,2, 4,2...
Bu sözde değişmezleri de kullanmalısınız (bilirsiniz, eğlence için): -inf, +inf ve nan.
7
C++ - Modül 06 C++ yayınları
Sınıfınızın beklendiği gibi çalıştığını test etmek için bir program yazın.
İlk önce parametre olarak iletilen değişmez bilginin türünü tespit etmeniz, onu dönüştürmeniz gerekir.
string'i gerçek türüne dönüştürün, ardından onu açıkça diğer üç veri türüne dönüştürün. Son olarak,
sonuçları aşağıda gösterildiği gibi görüntüleyin.
Bir dönüşümün anlamı yoksa veya taşarsa, bilgilendirmek için bir mesaj görüntüleyin
kullanıcı tür dönüştürmenin imkansız olduğunu. İhtiyacınız olan herhangi bir başlığı ekleyin
Sayısal sınırları ve özel değerleri yönetin
*/