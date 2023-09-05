#ifndef SCALAR_H
#define SCALAR_H

#include <iostream>
#include <string>

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

class ScalarConverter
{
    private:
        //
    public:
        //
        static int atoi(std::string av);
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