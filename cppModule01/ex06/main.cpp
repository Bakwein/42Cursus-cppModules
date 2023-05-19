/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:56:45 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:56:56 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc,char **argv)
{
    if(argc == 2)
    {
        Harl h;
        h.complain(argv[1]);
    }
    else
    {
        std::cout << "argc must be 2. ./harlFilter <things> " << std::endl;
    }
    return 0;
}