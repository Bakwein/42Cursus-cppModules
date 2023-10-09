#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
    private:
        std::vector<int> vec;
        unsigned int N;
        Span();
    public:
        Span(unsigned int n);
        Span(const Span &rhs);
        ~Span();
        Span& operator=(Span const& rhs);

        void printVector(void)const;
        void addNumber(int num);
        void addNumber(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
        long int shortestSpan()const;
        long int longestSpan()const;

        void editValue(unsigned int index, int value);

        unsigned int getN()const;
        void setN(unsigned int n);

        std::vector<int> getVec()const;

};

/*
Maksimum N tam sayıyı depolayabilen bir Span sınıfı geliştirin. N imzasız bir int'dir
değişkendir ve yapıcıya iletilen tek parametre olacaktır.
Bu sınıf, tek bir sayı eklemek için addNumber() adında bir üye işlevine sahip olacaktır.
Span'a. Doldurmak için kullanılacaktır. Varsa yeni bir öğe eklemeye yönelik herhangi bir girişim
Zaten saklanan N öğe varsa bir istisna oluşturmalıdır.
Daha sonra iki üye işlevi uygulayın: shortestSpan() ve longSpan()
Sırasıyla en kısa açıklığı veya en uzun açıklığı (veya mesafeyi) bulacaklardır.
Saklanan tüm numaralar arasında tercih ettiğiniz) ve onu geri döndürün. Kayıtlı numara yoksa,
veya yalnızca bir tane varsa aralık bulunamıyor. Böylece bir istisna atın.
Elbette kendi testlerinizi yazacaksınız ve bunlar önceki testlerden çok daha kapsamlı olacak.
aşağıdakiler. Span'ınızı en az 10.000 sayıyla test edin. Daha fazlası olurdu
daha iyi.


Son olarak Span'ınızı bir dizi yineleyici kullanarak doldurmak harika olurdu.
addNumber()'a binlerce çağrı yapmak çok sinir bozucu. Bir üye işlevi uygulayın
Tek bir aramada Span'ınıza birçok numara eklemek için.
*/

#endif