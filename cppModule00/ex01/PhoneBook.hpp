/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:42:58 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 18:43:01 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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