#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{   
    {
        try
        {
            PresidentialPardonForm deneme;
            Bureaucrat b1("bureaucrat", 1);
            PresidentialPardonForm f1("target");

            //b1.signForm(f1);
            b1.executeForm(f1);
        }
        catch(const std::exception& e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
         try
        {
            Bureaucrat b1("bureaucrat", 1);
            PresidentialPardonForm f1("target");

            b1.signForm(f1);
            b1.executeForm(f1);
        }
        catch(const std::exception e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    
    {
        try
        {
            Bureaucrat b1("bureaucrat", 1);
            Bureaucrat b2("bureaucrat2",20);
            Bureaucrat b3("bureaucrat3",20);

            PresidentialPardonForm f1("ppFORM");
            RobotomyRequestForm f2("rrFORM");
            ShrubberyCreationForm f3("scFORM");
            ShrubberyCreationForm f4("sefaT");
            
            std::cout << std::endl;
            b1.signForm(f1);
            b2.signForm(f2);
            b3.signForm(f3);
            b2.signForm(f4);
            std::cout << std::endl;

            b1.executeForm(f1);
            b2.executeForm(f2);
            b3.executeForm(f3);
            b1.executeForm(f4);

        }
        catch(const std::exception &e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
        try
        {
            Bureaucrat b1("sefa",20);
            
            // for testing 
            //Bureaucrat b2("bur2"); // grade problem- default grade is 150
            //Bureaucrat b2("bur2",10); // -> already signed

            Bureaucrat b3("bur3",27);
            
            RobotomyRequestForm f1("form1");
            

            std::cout << std::endl;

            b1.signForm(f1);
            //b2.signForm(f1);
            std::cout << std::endl << std::endl;

        /* forms dont execute if they do not signed
            b3.executeForm(f2);
            std::cout << "deneme" << std::endl;
            RobotomyRequestForm f2("form2");
        */
        }
        catch(const std::exception &e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
        try
        {
            Bureaucrat b1("bur1",5);
            
            //Bureaucrat b1("bur1",20); // signed but not executed
            //Bureaucrat b1("bur1",25);

            //Bureaucrat b1("bur1",26); // not signed

            Bureaucrat b2("bur2",45);


            Bureaucrat b3("bur3",137);

            

            PresidentialPardonForm f1("ppF"); // sign 25, exec 5 
            RobotomyRequestForm f2("rrF"); //  sign 72, exec 45
            ShrubberyCreationForm f3("scF"); // sign 145, exec 137

            b1.signForm(f1);
            b2.signForm(f2);
            b3.signForm(f3);

            b1.executeForm(f1);
            b2.executeForm(f2);
            b3.executeForm(f3);
        }
        catch(const std::exception &e)
        {
            std::cout << B_RED <<e.what() << RESET <<std::endl;
        }
    }
    return (0);
}