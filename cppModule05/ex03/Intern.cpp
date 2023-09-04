#include "Intern.hpp"
#include "AForm.hpp"

Intern::Intern(void)
{
    std::cout << "default intern const. called" << std::endl;
}

Intern::Intern(Intern const &src)
{
    std::cout << "intern Copy const. called" << std::endl;
    *this = src;
}

Intern &Intern::operator=(Intern const &rhs)
{
    if(this != &rhs)
        return *this;
    std::cout << "Intern's copy assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern(void)
{
    std::cout << "Intern's destructor called" << std::endl;
}

AForm *Intern::makePresidential(std::string target)
{
    return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomy(std::string target)
{
    return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubbery(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeForm(std::string formName, std::string targetForm)
{
    std::string formNames[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
    AForm *(Intern::*arr[3])(std::string target) = {&Intern::makePresidential, &Intern::makeRobotomy, &Intern::makeShrubbery};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formName)
        {
            std::cout << CYAN << "Intern creates " << formName << RESET << std::endl;
            return (this->*arr[i])(targetForm); // Call the member function through the instance
        }
    }

    std::cout << RED << "Intern cannot create a form!!" << RESET << std::endl;
    return NULL;
}
