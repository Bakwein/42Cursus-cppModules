#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    {
    
    try
    {
        Bureaucrat b("b", 1);
        Bureaucrat b2("sefa",24);
        Bureaucrat xd("bure",3);
        Form f("f", 1, 1);
        Form f1("form2",42,24);
        Form f2("Form3",32,122);
        b.signForm(f);
        std::cout << f;
        b.signForm(f1);
        std::cout << f;
        b.signForm(f2);
        std::cout << f;
        b.signForm(f1);
        //std::cout << "za\n";
    }
    catch(const std::exception& e)
    {
        std::cout << RED <<e.what() << '\n' << RESET;
    }
    }

   std::cout << BLUE <<"---------------------" << std::endl << RESET;
   {
        try
        {
            Form f("f", 1, 1222);
        }
        catch(const std::exception& e)
        {
            std::cout << RED <<e.what() << '\n' << RESET;
        }
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;
    {
        try
        {
            Form f("f", 1222, 1);
        }
        catch(const std::exception& e)
        {
           std::cout << RED <<e.what() << '\n' << RESET;
        }
    }

    std::cout << BLUE <<"---------------------" << std::endl << RESET;
    {
        try
        {
            Form f("f", -1222, -12222);
        }
        catch(const std::exception& e)
        {
            std::cout << RED <<e.what() << '\n' << RESET;
        }
    }

   std::cout << BLUE <<"---------------------" << std::endl << RESET;
    {
        try
        {
            Form f("f", 23, 24);
            Bureaucrat b("sefaT", 124);
            //f.beSigned(b);
            b.signForm(f);
        }
        catch(const std::exception& e)
        {
            std::cout << RED <<e.what() << '\n' << RESET;
        }
    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;

    {
        try
        {
            Form f("f", 23, 24);
            Bureaucrat b("sefaT", 1);
            f.beSigned(b);
            b.signForm(f);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        

    }
    std::cout << BLUE <<"---------------------" << std::endl << RESET;
    {
    {
        try
        {
            Bureaucrat b("b", 1);
            Bureaucrat b2("sefa",24);
            Bureaucrat xd("bure",3);
            Form f0("form0", 1, 1);
            Form f1("form1",42,24);
            Form f2("Form2",32,122);
            Form f3("Form3",23,123);
            b.signForm(f0);
            f1.beSigned(b2);
            xd.signForm(f2);
            xd.signForm(f3);

            std::cout << xd;
            std::cout << f3;
        }
        catch(const std::exception& e)
        {
            std::cout << RED <<e.what() << '\n' << RESET;
        }
    }


    //system("leaks bureaucrat2");
    return (0);
}