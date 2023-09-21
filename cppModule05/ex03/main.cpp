#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request",         "Bender");
            free(rrf);

        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
    }
    
    std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
            free(rrf);
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
   std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

   {
        try
        {   
            Bureaucrat bur1("sefaT",1);
            Intern intern1;
            AForm *rff = intern1.makeForm("ShrubberyCreationForm", "second page");
            std::cout << *rff;
            bur1.signForm(*rff);
            bur1.executeForm(*rff);
            std::cout << "\n";

            Bureaucrat bur2("ali",1);
            Intern intern2;
            AForm *rff2 = intern2.makeForm("PresidentialPardonForm", "third page");
            std::cout << *rff2;
            bur2.signForm(*rff2);
            bur2.executeForm(*rff2);
            std::cout << "\n";

            Bureaucrat bur3("veli",1);
            Intern intern3;
            AForm *rff3 = intern3.makeForm("ShrubberyCreationForm", "fifth page");
            std::cout << *rff3;
            bur3.signForm(*rff3);
            bur3.executeForm(*rff3);
            std::cout << "\n";
            free(rff);
            free(rff2);
            free(rff3);
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
   }
    return (0);
}