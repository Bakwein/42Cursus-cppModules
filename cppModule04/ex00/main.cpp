/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:35:45 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:35:45 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::cout << "-------------Animal Test-------------" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << "Type : " << meta->getType() << std::endl;
	std::cout << "Type : " << j->getType() << std::endl;
	std::cout << "Type : " << i->getType() << std::endl;

	std::cout << std::endl;
	meta->makeSound();
	i->makeSound();
	j->makeSound();
	

	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	
	std::cout << std::endl;
	std::cout << "-----------WrongAnimal Test-----------" << std::endl;
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << std::endl;
	std::cout << "Type : " << wa->getType() << std::endl;
	std::cout << "Type : " << wc->getType() << std::endl;

	std::cout << std::endl;
	wa->makeSound();
	wc->makeSound();

	std::cout << std::endl;
	delete wa;
	delete wc;

	return 0;
}
