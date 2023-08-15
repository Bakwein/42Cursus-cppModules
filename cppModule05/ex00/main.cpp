#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b("Bureaucrat", 150);
        std::cout << b;
        b.incrementGrade(10);
        std::cout << "???" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "---------------------" << std::endl;
    try
    {
        Bureaucrat b("Bureaucrat", 1);
        std::cout << b;
        b.decrementGrade(10);
        std::cout << "???" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat b2;
        Bureaucrat b5 = b2;
        b5.decrementGrade(50);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat b3;
        Bureaucrat b4(b3);
        b4.incrementGrade(2);
    }
    catch(Bureaucrat::GradeTooLowException &l)
    {
        std::cout << "low excp." << std::endl;
        std::cout << l.what() << std::endl;
    }
    catch(Bureaucrat::GradeTooHighException &h)
    {
        std::cout << "high excp." << std::endl;
        std::cout << h.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << "all excp." << std::endl;
        std::cout << e.what() << std::endl;
    }

    std::cout << "---------------------" << std::endl;

    try
    {
        Bureaucrat b6("Bureaucrat", 2);
        std::cout << b6;
        b6.decrementGrade(1);
        b6.decrementGrade(10);
    }
    catch (const Bureaucrat::GradeTooHighException &h)
    {
        std::cout << h.what() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }

    return (0);
}