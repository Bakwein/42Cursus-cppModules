#include "Bureaucrat.hpp"

int main()
{

    try
    {
        Bureaucrat xd("Sefa T",1905);
        std::cout << "BUNU YAZDIRMAYACAKK!" << xd;
    }
    catch(const std::exception& e1)
    {
        std::cout << RED <<e1.what() << '\n' << RESET;
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat xd("stunca",-1905);
        std::cout << "BUNU YAZDIRMAYACAKK!" << xd;
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
        b.incrementGrade(10);
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
        b.decrementGrade(10);
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
        Bureaucrat b5 = b2;
        b5.decrementGrade(50);
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << std::endl << RESET;
    }
    
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat b3;
        Bureaucrat b4(b3);
        b4.incrementGrade(2);
    }
    catch(Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "low excp." << std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }
    catch(Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "high excp." << std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }
    catch(const std::exception& e)
    {
        std::cout << "all excp." << std::endl;
        std::cout << RED << e.what() << std::endl << RESET;
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    try
    {
        Bureaucrat b6("Bureaucrat", 2);
        std::cout << b6;
        b6.decrementGrade(1);
        b6.decrementGrade(10);
    }
    catch (const Bureaucrat::GradeTooHighException &h)
    {
        std::cout << RED << h.what() << std::endl << RESET;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << std::endl << RESET;
    }

    return (0);
}