#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    try
    {
        if(argc != 2)
        {
            throw BitcoinExchange::argcError    ();
        }
        else
        {
            BitcoinExchange b(argv[1]);
            b.run();
        }
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
}

/*
Belirli miktarda Bitcoin'in değerini çıkaran bir program oluşturmalısınız.
belirli bir tarihte.
Bu program, bitcoin fiyatını temsil edecek csv formatında bir veritabanı kullanmalıdır.
mesai. Bu veritabanı bu konu ile sağlanmaktadır.
Program, farklı fiyatları/tarihleri ​​saklayan ikinci bir veritabanını girdi olarak alacaktır.
değerlendirmek.
Programınız şu kurallara uymalıdır:
• Programın adı btc'dir.
• Programınız argüman olarak bir dosya almalıdır.
• Bu dosyadaki her satır şu formatı kullanmalıdır: "tarih | değer".
• Geçerli bir tarih her zaman şu formatta olacaktır: Yıl-Ay-Gün.
• Geçerli bir değer, 0 ile 1000 arasında bir kayan nokta veya pozitif bir tam sayı olmalıdır.( yani template olarak alacağız)
Bunu doğrulamak için kodunuzda en az bir container kullanmalısınız
egzersiz yapmak. Olası hataları uygun bir yaklaşımla ele almalısınız.
hata mesajı.


$> head input.txt
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
$>
Programınız giriş dosyanızdaki değeri kullanacaktır.
Programınız çarpılan değerin sonucunu standart çıktıda göstermelidir.
Veritabanınızda belirtilen tarihe göre döviz kuruna göre.
Girişte kullanılan tarih DB'nizde mevcut değilse, o zaman
DB'nizde bulunan en yakın tarihi kullanmalısınız. kullanmaya dikkat edin
üst tarih değil, alt tarih.

$> ./btc
Error: could not open file.
$> ./btc input.txt
2011-01-03 => 3 = 0.9
2011-01-03 => 2 = 0.6
2011-01-03 => 1 = 0.3
2011-01-03 => 1.2 = 0.36
2011-01-09 => 1 = 0.32
Error: not a positive number.
Error: bad input => 2001-42-42
2012-01-11 => 1 = 7.1
Error: too large a number.
$>

Uyarı: Bu alıştırmayı doğrulamak için kullandığınız container
artık bu modülün geri kalanı için kullanılabilir.

*/