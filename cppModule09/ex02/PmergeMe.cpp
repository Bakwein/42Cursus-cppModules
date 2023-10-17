#include <PmergeMe.hpp>
#include <iostream>

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
void	print(T const& container)
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


}
