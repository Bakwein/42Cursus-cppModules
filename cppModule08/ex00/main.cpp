#include "easyfind.hpp"

#include <vector>
#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <stack>
#include <queue>

# define RED        "\033[0;31m"
# define RESET        "\033[0m"


int main()
{
    {
        try
        {
            std::array<int,5> arr1 = {1,2,3,4,5};
            easyfind(arr1,2);
            easyfind(arr1,21);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }

    std::cout << "-----------------------------"<< std::endl;
    {
        try
        {
            std::vector<int> v1; // 1 2 3 4 -42
            v1.push_back(1);
            v1.push_back(2);
            v1.push_back(3);
            v1.push_back(4);
            v1.push_back(-42);

            easyfind(v1,-42);
            easyfind(v1,42);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }
    std::cout << "-----------------------------"<< std::endl;
    {
        try
        {
            std::deque<int> dq; 
            dq.push_back(1905);
            dq.push_front(-23);
            dq.push_back(55);
            dq.push_front(-2);

            easyfind(dq,55);
            easyfind(dq,142);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }

    std::cout << "-----------------------------"<< std::endl;
    {
        try
        {
            std::forward_list<int> fl; 
            fl.push_front(23);
            fl.push_front(52);
            fl.push_front(-25);
            fl.push_front(-52);
            fl.push_front(0);
            fl.pop_front();

            easyfind(fl,0);
            easyfind(fl,-52);

            std::cout << "\n";
            fl.pop_front();
            fl.pop_front();
            fl.pop_front();
            fl.pop_front();
            easyfind(fl,0);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }

    std::cout << "-----------------------------"<< std::endl;
    {
        try
        {
            std::list<int> l; 
            l.push_back(23);
            l.push_front(-52);
            l.push_front(0);
            l.pop_front();
            l.pop_back();

            easyfind(l,23);
            easyfind(l,-23);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }

    
}