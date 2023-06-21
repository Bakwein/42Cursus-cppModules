/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:27:13 by stunca            #+#    #+#             */
/*   Updated: 2023/05/31 13:45:42 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"


int	main()
{
	FragTrap	ft;
	ScavTrap	st;
	ClapTrap	ct;

	ft.attack("Zombie");
	ft.highFivesGuys();
	ft.takeDamage(25);
	ct.attack("omg");
	ft.beRepaired(22);
	ft.highFivesGuys();
	st.attack("xd");
	st.guardGate();
	std::cout << "-----------------" << std::endl;

}