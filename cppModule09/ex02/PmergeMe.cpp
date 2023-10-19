#include "PmergeMe.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(PmergeMe const &other)
{
    *this = other;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &other)
{
    if (this != &other)
    {
        *this = other;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
}

//T::sometype'in bir tür adına mı yoksa T'nin statik bir üyesine mi atıfta bulunacağını bilmiyor.
/*
GitHub Copilot: `typename` anahtar kelimesi, bir şablon sınıfın veya şablon fonksiyonunun bir tür adı olarak kullanılan bir isim belirleyicinin bir tür adı olduğunu belirtmek için kullanılır. 
Örneğin, `T::const_iterator` ifadesi, `T` sınıfının `const_iterator` türünden bir üyesine atıfta bulunur. Ancak, `T` bir şablon sınıfı olduğunda, `const_iterator` bir tür adı olmayabilir. Bu durumda, `typename` anahtar kelimesi kullanılarak, `const_iterator`'un bir tür adı olduğu belirtilir. 
Yani, `typename T::const_iterator` ifadesi, `T` sınıfının `const_iterator` türünden bir üyesine atıfta bulunur ve `typename` anahtar kelimesi, `const_iterator`'un bir tür adı olduğunu belirtir.
*/
template <typename T>
void	PmergeMe::print(T const& container)
{
	typename T::const_iterator it = container.begin();
	typename T::const_iterator ite = container.end();
	while (it != ite)
	{
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
}

//YARIM BU DEVAM ET
PmergeMe::PmergeMe(int ac, char **av)
{
	(void)ac;
	(void)av;
	std::deque<int> deque_;
	std::list<int> list_;

	srand(time(NULL)); // NEDEN??

	for(int i = 1; i < ac;i++)
	{
		int tmp = atoi(av[i]);
		if(tmp <= 0)
		{
			std::cout << "Error: negative number" << std::endl;
			return ;
		}
		deque_.push_back(tmp);
		list_.push_back(tmp);


	}
	std::cout << "Before: ";
	print(deque_);

	clock_t start = clock();
	mergeInsertSortDeque(deque_);
	clock_t end = clock();
	double time1 = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;

	clock_t start2 = clock();
	mergeInsertSortList(list_);
	clock_t end2 = clock();
	double time2 = static_cast<double>(end2 - start2) / CLOCKS_PER_SEC* 1000;

	std::cout << "After: ";
	print(deque_);
	std::cout << "Time to process a range of " << deque_.size() << " elements with std::deque container: " << time1 << " us" << std::endl;
    std::cout << "Time to process a range of " << deque_.size() << " elements with std::list container: " << time2 << " us" << std::endl;
	/*if(deque_ == std::deque<int>(list_.begin(), list_.end()))
		std::cout << "The sorted sequences are equal." << std::endl;
	else
		std::cout << "The sorted sequences are not equal." << std::endl;
	*/
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &deq)
{
	std::deque<int>::iterator it1,it2;
	for(it1 = deq.begin() + 1; it1 != deq.end(); ++it1)
	{
		int temp = *it1;
		it2 = it1;
		while(it2 != deq.begin() && *(std::prev(it2)) > temp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}
}

void PmergeMe::mergeInsertSortList(std::list<int> &list)
{
	std::list<int>::iterator it1,it2;
	for(it1 = ++list.begin(); it1 != list.end(); ++it1)
	{
		int temp = *it1;
		it2 = it1;
		while(it2 != list.begin() && *(std::prev(it2)) > temp)
		{
			*it2 = *(std::prev(it2));
			std::advance(it2, -1);
		}
		*it2 = temp;
	}
}
