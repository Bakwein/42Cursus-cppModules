#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat b("b", 1);
    Form f("f", 1, 1);
    try
    {
       
        b.signForm(f);
        std::cout << f;
    }
    catch(const std::exception& e)
    {
        std::cout << b.getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
    }
    return (0);
}