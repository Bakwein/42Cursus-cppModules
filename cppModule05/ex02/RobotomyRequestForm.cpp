#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45) , target("default")
{
    std::cout << "RobotomyRequestForm's default const." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) :AForm("RobotomyRequestForm", 72, 45) , target(target)
{
    std::cout << "RobotomyRequestForm's name const." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &rhs) : AForm("RobotomyRequestForm", 72, 45) , target(rhs.target)
{
    *this = rhs;
    std::cout << "RobotomyRequestForm's copy const." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rrf)
{
    AForm::operator=(rrf);
    target = rrf.target;
    std::cout << "RobotomyRequestForm opeator= called" << std::endl;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "RobotomyRequestForm Destructor called" << std::endl; 
}

bool RobotomyRequestForm::execute(const Bureaucrat &executor)const
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
        std::cout << "DRILLING NOISE!!!!!!!! "  << std::endl;
        std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"<< std::endl;
        std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"<< std::endl;
        std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"<< std::endl;
        std::cout << "DRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR"<< std::endl;
        srand(time(0));
        int num = rand() % 2;
        if(num)
        {
            std::cout << this->target << " has been robotomized" << std::endl;
        }
        else
        {
            std::cout << "The robotomy failed" << std::endl;
        }
        return true;
    }
}