#ifndef PMERGE_ME_HPP
#define PMERGE_ME_HPP

#include <deque>
#include <list>

class PmergeMe
{
    public:
        
        PmergeMe();
        PmergeMe(PmergeMe const &other);
        PmergeMe &operator=(PmergeMe const &other);
        ~PmergeMe();

        PmergeMe(int ac, char **av);

        template <typename T>
        void    print(T const &container);
        void mergeInsertSortDeque(std::deque<int> &deque);
        void mergeInsertSortList(std::list<int> &list);




        
};


#endif