/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:38:13 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:38:15 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// CREATING RANDOM ZOMBIE
void randomChump(std::string name)
{
    Zombie random(name);
    random.announce();
}