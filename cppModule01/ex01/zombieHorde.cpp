/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:40:32 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:40:34 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0)
        return NULL;
    Zombie *zombieArray = new Zombie[N];
    for(int i = 0; i < N; i++)
    {
        zombieArray[i].setName(name);
    }
    return zombieArray;

}