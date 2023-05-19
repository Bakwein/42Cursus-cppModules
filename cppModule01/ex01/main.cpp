/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 19:40:30 by stunca            #+#    #+#             */
/*   Updated: 2023/05/19 19:40:31 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int N;
    std::string name;

    std::cout << "Please enter name:";
    std::getline(std::cin, name);

    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Array len:";
    std::cin >> N;

   


    Zombie *array = zombieHorde(N,name);
    for(int x = 0;x < N;x++)
    {
        array[x].announce();
    }

    delete[] array;
    return 0;
}