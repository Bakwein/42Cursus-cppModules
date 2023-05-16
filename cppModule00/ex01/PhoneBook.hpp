#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include <iostream>

class PhoneBook
{
    Contact users[8];

    public:
        PhoneBook();
        ~PhoneBook();
        void exitCommand()const;
        void addCommand();
        void searchCommand()const;

};


#endif