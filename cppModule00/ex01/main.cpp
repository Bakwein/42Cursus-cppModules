/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:42:48 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 15:26:28 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

/*
 istream& getline(istream& is, 
           string& str, char delim);
2. Parameters: 

is: It is an object of istream class and tells the function about the stream from where to read the input from.
str: It is a string object, the input is stored in this object after being read from the stream.
delim: It is the delimitation character which tells the function to stop reading further input after reaching this character.

cin -> scanf
getline -> fgets

--------

#include <string>
int string::compare (const string& str) const
Returns:
0 : if both strings are equal.
A value < 0 : if *this is shorter than str or,
first character that doesn't match is smaller than str.
A value > 0 : if *this is longer than str or,
first character that doesn't match is greater
*/

int main()
{
    PhoneBook pb1;
    std::string input;

    while(1)
    {
        std::cin.clear();
        std::cout << CYAN<<"ENTER ADD, SEARCH or EXIT !" << END << std::endl;
        std::cout << "📖" << CYAN << ":" << END;
        std::getline(std::cin,input);
        if(std::cin.eof() || !input.compare("EXIT")) // eof-> ctrl+d
            pb1.exitCommand();
        else if(!input.compare("ADD"))
            pb1.addCommand();
        else if(!input.compare("SEARCH"))
            pb1.searchCommand();
        else
        {
            std::cout << RED<<"You entered wrong word! Please use ADD,SEARCH or EXIT" << END << std::endl;

        }
    }
    return 0;
}

