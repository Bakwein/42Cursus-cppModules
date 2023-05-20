/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:55:07 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 23:21:57 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mystream.hpp"


// ./fl "filename" "string_to_replace" "replacement_string" 
int main(int argc,char **argv)
{
    if(argc != 4)
    {
        return 0;
    }

    myStream myStr(argv[1]);
    myStr.replace(argv[2],argv[3]);
}