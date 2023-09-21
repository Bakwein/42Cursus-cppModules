#include "AForm.hpp"

//int AForm::lowGradeFlag = 0;

AForm::AForm(): name("default"),_signed(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "Default constructor called" << std::endl;

}

AForm::AForm(std::string name): name(name),_signed(false),gradeToSign(150),gradeToExecute(150)
{
    std::cout << "Name constructor called" << std::endl;
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name),_signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    std::cout << "Constructor called" << std::endl;
    this->isBetween();
}

AForm::~AForm()
{
    std::cout << this->name <<"'s AForm destructor called" << std::endl;
}

AForm::AForm(AForm const& f) : name(f.name), _signed(f._signed), gradeToSign(f.gradeToSign), gradeToExecute(f.gradeToExecute)
{
    std::cout << "Copy const called" << std::endl;
    *this = f;
}

AForm& AForm::operator=(AForm const &f)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &f)
    {
        this->_signed = f._signed;
    }
    return *this;
}

std::string AForm::getName()const{return name;}
bool        AForm::getSigned()const{return _signed;}
int         AForm::getGradeToSign()const{return gradeToSign;}
int         AForm::getGradeToExecute()const{return gradeToExecute;}


void    AForm::beSigned(Bureaucrat &bur)
{
    if(bur.getGrade() > this->getGradeToSign())
    {
        std::cout << bur.getGrade()<<   " " <<  this->getGradeToSign() << std::endl;
        std::cout << RED <<bur.getName() << " couldn't sign " << this->getName() << " because grade problem" << RESET <<std::endl;
        //lowGradeFlag = 1;
        throw AForm::GradeTooLowException();
    }
    else if(_signed) //true
    {
        std::cout << RED << bur.getName() << " couldn't sign " << this->getName() << " because it's already signed" << RESET << std::endl;
        throw AForm::AFormAlreadySigned();
    }
    else if(!_signed) //false
    {
        _signed = true;
        bur.signCount++;
        //std::cout << GREEN <<"AForm " << this->getName() << " is signed by " << bur.getName() <<  RESET << std::endl;
        std::cout << GREEN << bur.getName() << " signed " << this->getName() <<RESET << std::endl;
    }
}

const char	*AForm::GradeTooLowException::what() const throw()
{
    //if(!lowGradeFlag)
        return ("AForm:Grade is too low");
    //return "";
}

void    AForm::isBetween()
{
    if(gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    else if(gradeToSign < 1 || gradeToSign < 1)
        throw AForm::GradeTooHighException();
}

std::ostream& operator<<(std::ostream& os, AForm const& f)
{
    os << PURPLE <<  "name: "<< f.getName() << ", _signed: " << f.getSigned() << ", gradeToSign: "<< f.getGradeToSign() << ", gradeToExecute:"<< f.getGradeToExecute()<< END <<std::endl;
    return os;
}