/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystream.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:53:05 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:53:06 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSTREAM_H
#define MYSTREAM_H

#include <iostream>
#include <string>
#include <fstream>

class myStream
{
    std::string text;
    std::string filename;
    public:
        myStream(char*);
        ~myStream();
        std::string getText();
        void replace(char*,char*);
};


#endif