/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:14:33 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 14:48:01 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

/*
int toupper(int ch);

#include <cctype>
while(argv[y])
        {
            x = 0;
            while(argv[y][x])
            {
                std::cout << char(toupper(argv[y][x]));
                x++;
            }
            y++;
        }

*/

int main(int argc, char **argv)
{
    if(argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else if(argc >= 2)
    {
        int x = 0;
        int y = 1;
        while(argv[y])
        {
            x = 0;
            while(argv[y][x])
            {
                if(argv[y][x] >= 97 && argv[y][x] <= 122)//a-z
                {
                    argv[y][x] -= 32;
                }
                std::cout << argv[y][x];
                x++;
            }
            y++;
        }
    }
    std::cout << std::endl;
    return 0;

}