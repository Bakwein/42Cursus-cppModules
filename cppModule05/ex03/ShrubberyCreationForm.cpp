#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137) , target("default")
{
    std::cout << "ShrubberyCreationForm's default const." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm("ShrubberyCreationForm", 145, 137) , target(target)
{
    std::cout << "ShrubberyCreationForm's name const." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &rhs) : AForm("ShrubberyCreationForm", 145, 137) , target(rhs.target)
{
    *this = rhs;
    std::cout << "ShrubberyCreationForm's copy const." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &scf)
{
    AForm::operator=(scf);
    target = scf.target;
    std::cout << "ShrubberyCreationForm opeator= called" << std::endl;
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl; 
}

bool ShrubberyCreationForm::execute(const Bureaucrat &executor)const
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
        std::cout << B_GREEN << "ShrubberyCreation file -> " << this->target + "_shrubbery"  <<  END << std::endl;
        std::ofstream file(this->target + "_shrubbery");
        file << "       _-_ " << std::endl;
        file << "    /~~   ~~\\ " << std::endl;
        file << " /~~         ~~\\ " << std::endl;
        file << "{               } " << std::endl;
        file << " \\  _-     -_  / " << std::endl;
        file << "   ~  \\\\ //  ~ " << std::endl;
        file << "_- -   | | _- _ " << std::endl;
        file << "  _ -  | |   -_ " << std::endl;
        file << "      // \\\\ " << std::endl;
        file << "-------------------" << std::endl; 
        file << "       _-_ " << std::endl;
        file << "    /~~   ~~\\ " << std::endl;
        file << " /~~         ~~\\ " << std::endl;
        file << "{               } " << std::endl;
        file << " \\  _-     -_  / " << std::endl;
        file << "   ~  \\\\ //  ~ " << std::endl;
        file << "_- -   | | _- _ " << std::endl;
        file << "  _ -  | |   -_ " << std::endl;
        file << "      // \\\\ " << std::endl;
        file.close();
        return true;
    }
}