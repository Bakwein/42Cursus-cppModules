#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>

/*
container_type

The container_type member type of a standard library container template is the type of the underlying container used by the template. For example, the container_type member type of the std::stack template is std::deque<T>
*/
//last in first out-LIFO
template<typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T, container>
{
    public:
        typedef typename container::iterator iterator;
        typedef typename container::const_iterator const_iterator;
        typedef typename container::reverse_iterator reverse_iterator;
        typedef typename container::const_reverse_iterator const_reverse_iterator;

        MutantStack();
        MutantStack(const MutantStack &rhs);
        ~MutantStack();
        MutantStack &operator=(MutantStack const& obj);

        iterator begin();
        iterator end();

        const_iterator cbegin()const;
        const_iterator cend()const;

        reverse_iterator rbegin();
        reverse_iterator rend();

        const_reverse_iterator crbegin()const;
        const_reverse_iterator crend()const;

};

#include "MutantStack.tpp"

#endif


/*
Artık daha ciddi şeylere yönelme zamanı. Tuhaf bir şey geliştirelim.
std::stack konteyneri çok hoş. Ne yazık ki yinelenemeyen tek STL Konteynerlerinden biridir. Bu çok kötü.
Peki bunu neden kabul edelim? Özellikle de insanları katletme özgürlüğünü alabilirsek
eksik özellikleri oluşturmak için orijinal yığın.
Bu adaletsizliği onarmak için std::stack konteynerini yinelenebilir hale getirmelisiniz.
Bir MutantStack sınıfı yazın. Bir std::stack cinsinden uygulanacaktır.
Tüm üye işlevlerinin yanı sıra ek bir özellik de sunacak: yineleyiciler.
Elbette her şeyin yolunda gittiğinden emin olmak için kendi testlerinizi yazıp teslim edeceksiniz.
beklenen.

*/