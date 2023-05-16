#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <cctype>

class Contact
{
    int id;
    std::string firstname;
    std::string lastname;
    std::string nick;
    std::string tel;
    std::string darkestSecret;

    public:
        //CONSTRUCTERS
        Contact();
        Contact(int,std::string,std::string,std::string,std::string,std::string);

        //DESTRUCTOR
        ~Contact();

        //GETTER
        int getId();
        std::string getFirstName()const;
        std::string getLastName()const;
        std::string getNick()const;
        std::string getTel()const;
        std::string getDarkestSecret()const;

        //SETTTER
        void setId(int);
        void setFirstName(std::string);
        void setLastName(std::string);
        void setNick(std::string);
        void setTel(std::string);
        void setDarkestSecret(std::string);

        // CLASS GETTER-SETTER
        void setContact(int);
        void getContact()const;
        void getUserInfo()const;

        //ANOTHER FUNCTIONS
        std::string getInput(std::string)const;
        std::string getLimited(std::string)const;

        
};

#endif