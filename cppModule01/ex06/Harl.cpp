#include "Harl.hpp"

Harl::Harl()
{

}

Harl::~Harl()
{

}

void Harl::debug(void)
{
    std::cout << GREEN << "[DEBUG]" << std::endl;
    std::cout <<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"<< END << std::endl;
}

void Harl::info(void)
{
    std::cout << BLUE << "[INFO]" << std::endl;
    std::cout <<"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << END <<std::endl;
}

void Harl::warning(void)
{
    std::cout << YELLOW << "[WARNING]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << END <<std::endl;
}

void Harl::error(void)
{
    std::cout << RED << "[ERROR]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now."<< END <<std::endl;
}

void Harl::complain(std::string level)
{
    std::string strList[4] = {"DEBUG","INFO","WARNING","ERROR"};
    int i = 0;
    for(i = 0;i < 4;i++)
    {
        if(strList[i] == level)
            break;
    }
    switch(i)
    {
        case 0:
            this->debug();
        case 1:
            this->info();
        case 2:
            this->warning();
        case 3:
            this->error();
            break;
        default:
            std::cout << PURPLE << "[ Probably complaining about insignificant problems ]" << END <<std::endl;
            break;
    }
}
/*
Eğer level, bir dizi öğesiyle eşleşirse, o öğeye karşılık gelen üye işlev (arr dizisindeki işaretçi) çağrılır. Bu, this işaretçisiyle arr[i] işaretçisinin birleştirilmesi ve ardından çağrı operatörü () kullanılarak gerçekleştirilir.

Yani complain fonksiyonu, level parametresi ile belirtilen seviyeye göre ilgili işlevi çağırır. Örneğin, eğer level "DEBUG" ise debug işlevi çağrılır.
*/