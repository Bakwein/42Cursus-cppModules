/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:36:32 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 16:36:32 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
//#include "Brain.hpp"
#define N 10

int main()
{
const Animal* j = new Dog();
const Animal* i = new Cat();

delete j;//should not create a leak
delete i;

std::cout << std::endl << std::endl;
Animal *animals[N];

for (int i = 0; i < N; i++)
{
	if (i & 1) // 1-3-5-7
		animals[i] = new Dog();
	else
		animals[i] = new Cat();
}
for (int i = 0; i < N; i++)
	delete animals[i];

std::cout << std::endl << std::endl;
Dog* d1 = new Dog(); // const yaparsam brain kısmını degistiremem
d1->setIdea(0,"heyo!");
d1->setIdea(1,"Hrrr.");
d1->printIdeas();

delete d1;
system("leaks brain");

return 0;
}