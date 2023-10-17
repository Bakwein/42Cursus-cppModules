#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
        {
            throw RPN::argcError();
        }
        else
        {
            std::string inp = argv[1];
            RPN r(inp);
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    
    return 0;
}

/*

Bu kısıtlamalara sahip bir program oluşturmalısınız:
• Programın adı RPN'dir.
• Programınız argüman olarak ters Lehçe matematik ifadesini almalıdır.
• Bu işlemde kullanılan ve argüman olarak iletilen sayılar her zaman daha az olacaktır
10'dan fazla. Hesaplamanın kendisi ve sonuç bu kuralı dikkate almaz.
• Programınızın bu ifadeyi işlemesi ve doğru sonucu çıktı olarak vermesi gerekir.
standart çıktı.
• Programın yürütülmesi sırasında bir hata meydana gelirse, bir hata mesajı verilmelidir.
standart çıktıda görüntülenir.
• Programınız şu belirteçlerle işlemleri gerçekleştirebilmelidir: "+ - / *".
Bunu doğrulamak için kodunuzda en az bir container kullanmalısınız
egzersiz yapmak.

Parantezleri veya ondalık sayıları yönetmenize gerek yok
Here is an example of a standard use:
$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" -> ((((8*9)-9)-9)-9)-4)+1 = 42
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error
$>


*/