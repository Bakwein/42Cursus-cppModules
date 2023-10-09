#include "Span.hpp"
#include <iostream>

# define RED        "\033[0;31m"
# define BLUE        "\033[0;34m"
# define RESET        "\033[0m"

int main()
{
    {
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET <<'\n';
    }
    
    
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try 
        {
            Span sp = Span(7);
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(-32);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.printVector();
            sp.editValue(0,-2);
            sp.editValue(1,525);
            sp.printVector();
            Span s(sp);
            s.printVector();
            Span s_ = s;
            s_.printVector();
            std::cout << s_.shortestSpan() << std::endl;
            std::cout << s_.longestSpan() << std::endl;

            //edit value if
            //sp.editValue(8,24);
            //sp.editValue(-1,24);
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(1);
            s.longestSpan();
            s.shortestSpan();
        }
        catch(const std::exception& e)
        {
            std::cerr << RED << e.what() << RESET << '\n';
        }    
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(0);
            s.addNumber(22);
            s.printVector();
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(2);
            s.addNumber(2);
            s.addNumber(-62);
            s.setN(6);
            s.addNumber(26);
            s.printVector();
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(10);
            s.addNumber(22);
            std::vector<int> tmp;
            tmp.push_back(25);
            tmp.push_back(-150);
            tmp.push_back(-25215);
            tmp.push_back(2126945);
            s.addNumber(tmp.begin(),tmp.end());
            s.printVector();

        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(4);
            s.addNumber(22);
            std::vector<int> tmp;
            tmp.push_back(25);
            tmp.push_back(-150);
            tmp.push_back(-25215);
            tmp.push_back(2126945);
            s.addNumber(tmp.begin(),tmp.end());
            s.printVector();

        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(20000);
            for(unsigned int i = 0;i < s.getN(); i++)
            {
                s.addNumber(i);
            }
            std::cout << s.shortestSpan() << std::endl;
            std::cout << s.longestSpan() << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << '\n';
        }
        
    }
    std::cout << BLUE << "-------------------------------- " << RESET << std::endl;
    {
        try
        {
            Span s = Span(10000000);
            for(unsigned int i = 0; i < s.getN();i++)
            {
                s.addNumber(i);
            }
            std::vector<int> temp = s.getVec();
            std::reverse(temp.begin(),temp.end());
            std::cout << s.shortestSpan() << std::endl;
            std::cout << s.longestSpan() << std::endl;
            
        }
        catch(const std::exception& e)
        {
            std::cout << RED << e.what() << RESET << std::endl;
        }
    }

    return 0;
}