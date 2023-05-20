/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:36:32 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 15:14:09 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"


/*
str.empty()
This function checks whether the string is empty or not. Function returns a Boolean value either true or false.
-
std::flush

Belleğe almadan direkt yazmayı sağlar.
C++'ta, std::ostream sınıfı (örneğin std::cout veya std::cerr) çıktı işlemlerini tamponlar. Bu tamponlama, çıktıyı daha verimli bir şekilde işlemek için yapılır. Normalde, çıktı tamponu dolana kadar (std::endl manipülatörü kullanıldığında veya std::ostream nesnesi yok edildiğinde) çıktı cihazına veri gönderilmez.

Ancak bazı durumlarda, çıktının hemen cihaza gönderilmesi gerekebilir. Bu durumlarda, std::flush manipülatörü kullanılır. std::flush kullanıldığında, çıktı tamponu hemen boşaltılır ve içeriği cihaza gönderilir. Böylece, çıktının anında görüntülenmesi veya başka bir programın çıktısını beklemesi gereken senaryolarda std::flush kullanılabilir.

--

*/

Contact::Contact()
{
    this->id = 0;
    this->firstname = "";
    this->lastname = "";
    this->nick = "";
    this->tel = "";
    this->darkestSecret = "";
}

Contact::Contact(int id,std::string firstname,std::string lastname,std::string nick,std::string tel,std::string darkestSecret)
{
    this->id = id;
    this->firstname = firstname;
    this->lastname = lastname;
    this->nick = nick;
    this->tel = tel;
    this->darkestSecret = darkestSecret;
}

Contact::~Contact(){return;};

int Contact::getId(){return id;}
std::string Contact::getFirstName()const{return firstname;}
std::string Contact::getLastName()const{return lastname;}
std::string Contact::getNick()const{return nick;}
std::string Contact::getTel()const{return tel;}
std::string Contact::getDarkestSecret()const{return darkestSecret;}

void Contact::setId(int id){this->id=id;}
void Contact::setFirstName(std::string firstname){this->firstname=firstname;}
void Contact::setLastName(std::string lastname){this->lastname=lastname;}
void Contact::setNick(std::string nick){this->nick=nick;}
void Contact::setTel(std::string tel){this->tel=tel;}
void Contact::setDarkestSecret(std::string darkestSecret){this->darkestSecret=darkestSecret;}

//istream& getline(istream& input_stream, string& output, char delim);
std::string Contact::getInput(std::string info)const
{
    std::string newInput;

    while(1)
    {
        std::cout << info;
        std::getline(std::cin, newInput);
        if(!newInput.empty())
        {
            if(islower(newInput[0]))
                newInput[0] = toupper(newInput[0]);
            break;
        }
        std::cout << "Input must not be empty" << std::endl;
    }
    return newInput;
}

std::string Contact::getLimited(std::string str)const
{
    if(str.length() > 10)
        return(str.substr(0,9) + ".");
    return (str); 
}

void Contact::setContact(int id)
{
    this->id = id;
    this->firstname = this->getInput("Enter First Name: ");
    this->lastname = this->getInput("Enter Last Name: ");
    this->nick = this->getInput("Enter Nick: ");
    while(1)
    {
        this->tel = this->getInput("Enter phone number: ");
        int a = 0;
        int flag = 0;
        while(this->tel[a])
        {
            if(!isdigit(this->tel[a]))
            {
                flag = 1;
                break;
            }
            a++;
        }
        if(flag == 0)
            break;
        else
        {
            std::cout << "Phone number does not contain letter" << std::endl;
        }
    }
    this->darkestSecret = this->getInput("Enter Darkest Secret: ");
}

void Contact::getContact()const
{
    if(this->firstname.empty() || this->lastname.empty() || this->nick.empty() || this->tel.empty() || this->darkestSecret.empty())
        return ;
    //std::left,std::right
    std::cout << "|" << std::setw(10)  << id << std::flush;
    std::cout << "|" << std::setw(10) << this->getLimited(this->firstname)<< std::flush;
    std::cout << "|" << std::setw(10) << this->getLimited(this->lastname)<< std::flush;
    std::cout << "|" << std::setw(10) << this->getLimited(this->nick)<< std::flush;
    std::cout << "|" << std::endl;
}

void Contact::getUserInfo()const
{
    if(!(this->id >= 0 && this->id <= 7))
    {
        std::cout << "No user is registered !" << std::endl;
        return;
    }
    std::cout << id << ". User's First Name: " << this->firstname << std::endl;
    std::cout << id << ". User's Last Name: " << this->lastname << std::endl;
    std::cout << id << ". User's Nick: " << this->nick << std::endl;
    std::cout << id << ". User's Phone Number: " << this->tel << std::endl;
    std::cout << id << ". User's Darkest Secret: " << this->darkestSecret << std::endl;
}