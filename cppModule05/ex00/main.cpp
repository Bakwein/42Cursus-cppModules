#include "Bureaucrat.hpp"

int main()
{
    try
    {
        //int m = 10 / 0;
        //(void)m;
        int x = 0;
        if(x != 0)
        {
            std::cout << GREEN << "x is not 0 " << RESET << std::endl;
        }
        else 
            throw x;
    }
    catch(const std::exception &e)
    {
        std::cout<< RED << e.what() << RESET << std::endl;
    }
    catch(int x)
    {
        std::cout <<  RED << x << " detected" << RESET << std::endl;
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        throw std::length_error("length exception when .....");
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << RESET <<'\n';
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        throw std::invalid_argument("inv arg");
        throw std::out_of_range("out of range");
    }
    /*catch(std::invalid_argument &e)
    {
        std::cout << RED << e.what() << RESET << std::endl;
    }
    */
    catch(std::out_of_range &s)
    {
        std::cout << RED << s.what() << RESET << std::endl;
    }
    catch(...)
    {
        std::cout << RED << "exception detected!! " << RESET << std::endl;
    }
    
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat xd("Sefa T",1905);
        std::cout << "THIS WILL NOT PRINT!" << xd;
    }
    catch(const std::exception& e1)
    {
        std::cout << RED <<e1.what() << '\n' << RESET;
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat xd("stunca",-1905);
        std::cout << "THIS WILL NOT PRINT!" << xd;
    }
    catch(const std::exception& e1)
    {
        std::cout << RED << e1.what() << '\n' << RESET;
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        std::cout << b;
        b.decrementGrade(10);
        std::cout << "???" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED <<e.what() << std::endl<< RESET;
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        std::cout << b;
        b.incrementGrade(10);
        std::cout << "???" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << RED << e.what() << std::endl << RESET;
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat b2;
        std::cout << b2;
        Bureaucrat b5;
        b5 = b2;
        std::cout << b5;
        b5.incrementGrade(50);
        std::cout << PURPLE <<"b5's grade-> " << b5.getGrade() << RESET <<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << std::endl << RESET;
    }
    
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat b3;
        std::cout << b3;
        Bureaucrat b4(b3);
        std::cout << b4;
        b4.decrementGrade(2);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << RED <<"low excp." << RESET<< std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << RED<<"high excp." << RESET <<std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }
    catch(const std::exception& e)
    {
        std::cout << RED <<"all excp." << RESET <<std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }
    catch(...)
    {
        std::cout << RED << "a thing that throwable" << RESET <<std::endl;
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat b6("Bureaucrat", 2);
        std::cout << b6;
        b6.incrementGrade(1);
        b6.incrementGrade(10);
    }
    catch (const Bureaucrat::GradeTooLowException &h)
    {
        std::cout << RED << "only low" << RESET << std::endl;
        std::cout << RED << h.what() << std::endl << RESET;
    }
    catch(const std::exception& e)
    {
        std::cout << RED <<"all except." << RESET<< std::endl;
        std::cout << RED << e.what() << RESET << std::endl;
    }

    return (0);
}