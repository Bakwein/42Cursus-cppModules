/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mystream.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:53:07 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:55:02 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystream.hpp"

myStream::myStream(char *filename)
{
    std::ifstream file(filename);
    std::string str = "";
    std::string temp;

    while(getline(file, temp))
    {
        str += temp + "\n";
    }
    text = str;
    this->filename = filename;
}

myStream::~myStream()
{
    this->filename += ".replace";
    std::cout << this->filename << " is created." << std::endl;
    std::ofstream out(this->filename);
    out << this->text;
    out.close();
}

std::string myStream::getText()
{
    return this->text;
}

void myStream::replace(char *src, char *dest)
{
    std::string newStr = "";
    const char *str = this->text.c_str();
    int i = 0,j,k;

    while(str[i])
    {
        j = k = 0;
        while(str[i+j] == src[k])
        {
            j++;
            k++;
            if(!src[k])
            {
                i +=j;
                newStr += dest;
            }
        }
        newStr += str[i++];
    }
    this->text = newStr;
}