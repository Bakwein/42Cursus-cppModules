#include "Form.hpp"

Form::Form(): name("default"),_signed(false),gradeToSign(150),gradeToExecute(150) , refOutput("")
{
    std::cout << "Default constructor called" << std::endl;
}

Form::Form(std::string name): name(name),_signed(false),gradeToSign(150),gradeToExecute(150),refOutput("")
{
    std::cout << "Name constructor called" << std::endl;
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name),_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute), refOutput("")
{
    std::cout << "Constructor called" << std::endl;
    this->isBetween();
}

Form::~Form()
{
    std::cout << this->name <<"'s Form destructor called" << std::endl;
}

Form::Form(Form const& f) : name(f.name), _signed(f._signed), gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute), refOutput("")
{
    std::cout << "Copy const called" << std::endl;
    *this = f;
}

Form& Form::operator=(Form const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &f)
    {
        this->_signed = f._signed;
    }
    return *this;
}

std::string Form::getName()const{return name;}
bool        Form::getSigned()const{return _signed;}
int         Form::getGradeToSign()const{return gradeToSign;}
int         Form::getGradeToExecute()const{return gradeToExecute;}


void    Form::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade() > this->getGradeToSign())
        throw Form::GradeTooLowException();
    else if(_signed)
    {
        std::cout << bur.getName() << " cannot sign " << this->getName() << " because it's already signed" << std::endl;
    }
    else if(!_signed)
    {
        _signed = true;
        std::cout << "Form " << this->getName() << " is signed by " << bur.getName() << std::endl;
    }
}

void    Form::isBetween()
{
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooHighException();
    else if(gradeToSign < 1 || gradeToSign < 1)
        throw Form::GradeTooLowException();
}

std::ostream& operator<<(std::ostream& os, Form const& f)
{
    os << "name: "<< f.getName() << ", _signed: " << f.getSigned() << ", gradeToSign: "<< f.getGradeToSign() << ", gradeToExecute:"<< f.getGradeToExecute()<< std::endl;
    return os;
}