#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", 25, 5) , target("default")
{
    std::cout << "PresidentialPardonForm's default const." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) :AForm("PresidentialPardonForm", 25, 5) , target(target)
{
    std::cout << "PresidentialPardonForm's name const." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &rhs) : AForm("PresidentialPardonForm", 25, 5) , target(rhs.target)
{
    *this = rhs;
    std::cout << "PresidentialPardonForm's copy const." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &ppf)
{
    AForm::operator=(ppf);
    target = ppf.target;
    std::cout << "PresidentialPardonForm opeator= called" << std::endl;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "PresidentialPardonForm Destructor called" << std::endl; 
}

bool PresidentialPardonForm::execute(const Bureaucrat &executor)const
{
    if(!this->getSigned())
    {
        throw AForm::AFormNotSigned();
        return false;
    }
    else if(executor.getGrade() > this->getGradeToExecute())
    {
        throw AForm::GradeTooLowException();
        return false;
    }
    else
    {
        std::cout << B_GREEN <<"Informs that " << this->target
		<< " has been pardoned by Zaphod Beeblebrox." << RESET <<std::endl;
        return true;
    }
}