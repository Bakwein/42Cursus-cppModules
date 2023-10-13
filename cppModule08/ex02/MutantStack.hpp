#ifndef MUTANT_STACK
#define MUTANT_STACK

#include <stack>
#include <deque>

/*
container_type

The container_type member type of a standard library container template is the type of the underlying container used by the template. For example, the container_type member type of the std::stack template is std::deque<T>
*/
//last in first out-LIFO

/*
Stack sınıfının template <class T, class Container = std::deque<T>> sözdizimi, deque'i temel kapsayıcı olarak belirtir. Bu, stack nesnesinin, deque'in tüm özelliklerini miras aldığını gösterir.

class MutantStack : public std::stack<T, container> ifadesi, MutantStack sınıfının std::stack sınıfından miras aldığını belirtir. Bu, MutantStack'in std::stack'in işlevselliğini devraldığı ve özelleştirebileceği anlamına gelir.

Iterator:
iterator, bir veri yapısı üzerinde gezinmek ve elemanları değiştirmek için kullanılır.
Değiştirilebilir verilere erişim sağlar.
Örneğin, bir dizi üzerinde dolaşırken, iterator kullanarak dizinin elemanlarını okuyabilir ve değiştirebilirsiniz.

Const_iterator:
const_iterator, bir veri yapısı üzerinde gezinirken elemanları değiştirmenize izin vermez.
Sadece elemanları okumak için kullanılır.
Bu, verilerin değiştirilmemesi gereken durumlarda kullanışlıdır.

Reverse_iterator:
reverse_iterator, bir veri yapısını tersten (sondan başa) dolaşmak için kullanılır.
Bu, özellikle bir veri yapısının sonundan başlayarak geriye doğru ilerlemeniz gereken durumlarda kullanışlıdır.

Const_reverse_iterator:
const_reverse_iterator, bir veri yapısını tersten dolaşırken elemanları değiştirmenize izin vermez.
Sadece elemanları okumak için kullanılır ve tersten dolaşır.
*/

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