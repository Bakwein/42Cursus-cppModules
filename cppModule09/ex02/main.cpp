#include "PmergeMe.hpp"
#include <iostream>



int main(int argc, char **argv)
{
    try
    {
        if(argc <= 1)
        {
            std::cout << "Error : wrong argc" << std::endl;
            return 0;
        }
        PmergeMe p(argc, argv);

    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
    
    return 0;

}

/*
Bu kısıtlamalara sahip bir program oluşturmalısınız:
• Programın adı PmergeMe'dir.
• Programınız argüman olarak pozitif tamsayı dizisini kullanabilmelidir.
• Programınız pozitif tamsayıları sıralamak için birleştirme-ekleme sıralama algoritmasını kullanmalıdır
sekans.

Açıklığa kavuşturmak için evet, Ford-Johnson algoritmasını kullanmanız gerekir.

Programın yürütülmesi sırasında bir hata meydana gelirse, bir hata mesajı görüntülenmelidir.
standart çıktıda

Kodunuzda en az iki farklı container kullanmalısınız.
Bu alıştırmayı doğrulayın. Programınızın şu adreste işlemesi gerekir:
en az 3000 farklı tamsayı.

Algoritmanızı her konteyner için uygulamanız önemle tavsiye edilir.
ve böylece genel bir işlevi kullanmaktan kaçınmak için. -> template

Satır satır görüntülemeniz gereken bilgilerle ilgili bazı ek yönergeleri burada bulabilirsiniz
standart çıktıda:
• İlk satırda açık bir metin ve ardından sıralanmamış pozitif ifadeyi görüntülemelisiniz
tamsayı dizisi.
• İkinci satırda açık bir metni ve ardından sıralanmış pozitifleri görüntülemelisiniz
tamsayı dizisi.
• Üçüncü satırda, kullanılan zamanı belirten açık bir metin görüntülemelisiniz.
pozitif tamsayıyı sıralamak için kullanılan ilk kabı belirterek algoritmanız
sekans. -> ilk container süresi
• Son satırda, kullanılan zamanı belirten açık bir metin görüntülemelisiniz.
pozitif tamsayıyı sıralamak için kullanılan ikinci kabı belirterek algoritmanız
sekans. -> ikinci container süresi

Sıralamanızı gerçekleştirmek için kullanılan zamanın görüntülenme biçimi
serbesttir, ancak seçilen hassasiyet
kullanılan iki konteyner arasındaki fark.

Bu örnekte zamanın belirtilmesi kasıtlı olarak gariptir.
Elbette tüm işlemlerinizi gerçekleştirmek için kullanılan zamanı belirtmeniz gerekir.
işlemleri, hem sıralama kısmı hem de veri yönetimi kısmı.

Uyarı: Önceki alıştırmalarda kullandığınız kap(lar)
burada yasak.
Yinelemelerle ilgili hataların yönetimi size bırakılmıştır.
takdir yetkisi.
*/