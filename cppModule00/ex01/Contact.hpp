/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:42:45 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 18:42:46 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip> //setw()
#include <cctype>

class Contact
{
    private:
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