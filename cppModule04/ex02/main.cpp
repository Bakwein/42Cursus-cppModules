/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:38:39 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:38:39 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "AAnimal.hpp"

int main(void)
{
	/* Error Area */
	// const AAnimal* animal = new AAnimal();
	// animal->makeSound();
	// delete animal;

	 const AAnimal* dog = new Dog();
	 const AAnimal* cat = new Cat();
	 std::cout << std::endl;

	 dog->makeSound();
	 cat->makeSound();
	 std::cout << std::endl;

	 delete dog;
	 delete cat;
	
	 return 0;
}