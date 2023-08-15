#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
    std::cout << "Default const. called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& src)
{
    std::cout << "Copy const called" << std::endl;
    *this = src;
}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &bur)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &bur)
    {
        grade = bur.getGrade();
    }
    return *this;
}


Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat Destructor called" << std::endl;
};

void Bureaucrat::isBetween()
{
    std::cout << this->name << ":" << this->grade << std::endl;
    if(grade > 150)
    {
        throw  Bureaucrat::GradeTooHighException();
    }
    else if(grade < 1)
    {
        throw  Bureaucrat::GradeTooLowException();
    }
    
}

void Bureaucrat::incrementGrade(int n)
{
    grade += n;
    isBetween();
}

void Bureaucrat::decrementGrade(int n)
{
    grade -= n;
    isBetween();
}

std::string Bureaucrat::getName()const{return name;}
int         Bureaucrat::getGrade()const{return grade;}

void        Bureaucrat::setGrade(int gr){grade = gr;}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bur)
{
    os << bur.getName() << ", bureaucrat grade " << bur.getGrade() << std::endl;
    return os;
}