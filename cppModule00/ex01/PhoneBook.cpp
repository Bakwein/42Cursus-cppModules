/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:42:56 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 15:24:48 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(){}
PhoneBook::~PhoneBook(){}


void PhoneBook::exitCommand()const
{
    std::cout << RED<<"Exit Command Detected, Shutting down!" << END<< std::endl;
    exit(0);
}

void PhoneBook::addCommand()
{
    static int userNumber;
    std::cout << "You are creating new user.." << std::endl;
    if(userNumber >= 8)
        userNumber = 0;
    std::cout << "User's number: " << userNumber << std::endl;
    this->users[userNumber].setContact(userNumber);
    userNumber++;
}

void PhoneBook::searchCommand()const
{
    int num;
    std::string input;

    std::cout << "|" << std::setw(10) << "" << "***** PHONE BOOK *****" << std::setw(11) << "" << "|" << std::endl;
    std::cout << "|" << std::setw(10) << "ID" << std::flush;
    std::cout << "|" << std::setw(10) << "FIRST NAME"<< std::flush;
    std::cout << "|" << std::setw(10) << "SURNAME"<< std::flush;
    std::cout << "|" << std::setw(10) << "NICKNAME"<< std::flush;
    std::cout << "|" << std::endl;
    for(int i = 0;i < 8;i++)
        this->users[i].getContact();
    while(1)
    {
        std::cout << "Enter id no: ";
        std::getline(std::cin, input);
        num = atoi(input.c_str()); // atoi'nin return değerine cast yapar
        std::cout << "Entered num: " << input << std::endl;
        if( std::cin.good() &&  (input.length() == 1) && (num >= 0 && num < 8) )
        {
            break;
        }
        std::cin.clear(); // he cin.clear() clears the error flag on cin
        std::cout << "You must be enter between 0-7 value!" << std::endl;

    }
    this->users[num].getUserInfo();
}

