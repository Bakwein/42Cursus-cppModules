/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 00:24:55 by stunca            #+#    #+#             */
/*   Updated: 2023/06/03 00:24:56 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file main.cpp
 * @author Görkem SEVER (gsever)
 * @brief This exercize about 'Abstract Class'.
 * @version 0.1
 * @date 2023-02-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void	JustSelfTestForAllocationLoop( void )
{
	// const AAnimal	*_animals[3] = { new AAnimal(), new Dog(), new Cat() };
	const AAnimal	*_animals[2] = { new Dog(), new Cat() };
	for (int a = 0; a < 2; a++)
	{
		std::cout << B_RED "------------------------" END << std::flush\
			<< std::endl << std::endl;
		std::cout << B_GREEN "Leaks Before: " << std::flush;
		system("leaks AAnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
		delete _animals[a];
		std::cout << B_GREEN "Leaks After: " << std::flush;
		system("leaks AAnimalBrain | grep 'leaked bytes'");
		std::cout << END << std::flush;
	}
}

static void	JustSelfTestForAllocation( void )
{
	// std::cout << YELLOW "*********** Default AAnimal Test Area ***********" END\
	// 	<< std::flush << std::endl;
	// const AAnimal	*a1 = new AAnimal();
	// std::cout << "~~~~~~~~~~~~~ AAnimal Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	// std::cout << B_GREEN "Leaks: " << std::flush;
	// system("leaks AAnimalBrain | grep 'leaked bytes'");
	// std::cout << END << std::flush;
	// delete a1;
	// std::cout << B_GREEN "Leaks: " << std::flush;
	// system("leaks AAnimalBrain | grep 'leaked bytes'");
	// std::cout << END << std::flush;
	// std::cout << B_RED "-------- AAnimals Allocated Destroyed! ------\n" END\
	// 	<< std::flush << std::endl;

	const AAnimal	*d1 = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Dog Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete d1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Dog Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;

	const AAnimal	*c1 = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ Cat Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete c1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Cat Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;

	const Dog		*doge = new Dog();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ doge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete doge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- Doge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl;

	const Cat		*catge = new Cat();
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << "~~~~~~~~~~~~~ catge Allocated Created! ~~~~~~~~~~~~~~~" << std::endl;
	delete catge;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << B_RED "-------- catge Allocated Destroyed! ------\n" END\
		<< std::flush << std::endl << std::endl;

	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain");
	std::cout << END << std::flush;

	std::cout << "Creating but not allocated memory area." GREEN\
		<< std::flush << std::endl;
	const AAnimal	*animal1 = NULL;
	const Dog		*dog1 = NULL;
	const Cat		*cat1 = NULL;
	const Brain		*brain1 = NULL;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	delete animal1;
	delete dog1;
	delete cat1;
	delete brain1;
	std::cout << B_GREEN "Leaks: " << std::flush;
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << END "Creating but not allocated memory area finished sir!."\
		<< std::flush << std::endl;
	std::cout << YELLOW "************************************************" END\
		<< std::flush << std::endl;
}

/**
 * @brief
 *
 * 	en;
		C++ virtual function:
- A C++ virtual function is a member function in the base class that you redefine in a derived class. It is declared using the virtual keyword.
- It is used to tell the compiler to perform dynamic linkage or late binding on the function.
- There is a necessity to use the single pointer to refer to all the objects of the different classes. So, we create the pointer to the base class that refers to all the derived objects. But, when base class pointer contains the address of the derived class object, always executes the base class function. This issue can only be resolved by using the 'virtual' function.
- A 'virtual' is a keyword preceding the normal declaration of a function.
- When the function is made virtual, C++ determines which function is to be invoked at the runtime based on the type of the object pointed by the base class pointer.

virtual means the the linkage will be dynamic not static
	Explaination:
	At the beginning, we had a statis relution of the function calls, It means that during the compilation, (the compiler) we already will know which function to call. And for this we use the type of the variable.
	The only way for the compiler to know the behavior of my object is by knowing its type. And we marked it as a Character type. and the compiler will assume that its a Character.
	Therefore, it uses the Character version of the function.
	It was a static link! means that during the compilation is determined it won't change later.
	However, during the compilation let assume that we don't want it as a Warriror, but as a Wizard.
	it may point on a Warrior once and on the Wizard once based on what the user input.
	Thanks to the virtual, the resulotion of the function call wil be dynamic. and it will be decided at runtime.

	When we call the member function, during the execution becauese it's a function with a dynamic link, it will look for the actual type of the object. It will walk
 through the inheritance tree to find the actual type.

	A virtual member function is called a method.
	The definition of a method is a member function which resulotion will be dynamic.

Rules of Virtual Function:

	- Virtual functions must be members of some class.
	- Virtual functions cannot be static members.
	- They are accessed through object pointers.
	- They can be a friend of another class.
	- A virtual function must be defined in the base class, even though it is not used.
	- The prototypes of a virtual function of the base class and all the derived classes must be identical. If the two functions with the same name but different prototypes, C++ will consider them as the overloaded functions.
	- We cannot have a virtual constructor, but we can have a virtual destructor.

*********************************************************************************************************

	tr;
C++ sanal işlevi:
- Bir C++ sanal işlevi, türetilmiş bir sınıfta yeniden tanımladığınız temel sınıftaki bir üye işlevdir. virtual anahtar sözcüğü kullanılarak bildirilir.
- Derleyiciye işlev üzerinde dinamik bağlantı veya geç bağlama gerçekleştirmesini söylemek için kullanılır.
- Farklı sınıfların tüm nesnelerine atıfta bulunmak için tek işaretçiyi kullanma zorunluluğu vardır. Böylece, tüm türetilmiş nesnelere atıfta bulunan temel sınıfın işaretçisini yaratıyoruz. Ancak, temel sınıf işaretçisi türetilmiş sınıf nesnesinin adresini içerdiğinde, her zaman temel sınıf işlevini yürütür. Bu sorun yalnızca 'sanal' işlevi kullanılarak çözülebilir.
- Bir 'sanal', bir işlevin normal bildiriminden önce gelen bir anahtar sözcüktür.
- İşlev sanal yapıldığında, C++ temel sınıf işaretçisi tarafından işaret edilen nesnenin türüne göre çalışma zamanında hangi işlevin çağrılacağını belirler.

 sanal, bağlantının statik değil dinamik olacağı anlamına gelir
     Açıklama:
     Başlangıçta, işlev çağrılarının statik bir çözümü vardı, bu, derleme sırasında (derleyici) hangi işlevi çağıracağımızı zaten bileceğimiz anlamına gelir. Bunun için de değişkenin tipini kullanıyoruz.
     Derleyicinin nesnemin davranışını bilmesinin tek yolu onun türünü bilmektir. Ve onu bir Karakter türü olarak işaretledik. ve derleyici onun bir Karakter olduğunu varsayacaktır.
     Bu nedenle, işlevin Karakter sürümünü kullanır.
     Statik bir bağlantıydı! derleme sırasında daha sonra değişmeyeceği belirlenir anlamına gelir.
     Ancak derleme sırasında onu bir Savaşçı olarak değil, bir Sihirbaz olarak istediğimizi varsayalım.
     kullanıcının girdisine bağlı olarak bir Savaşçıyı bir kez ve Sihirbazı bir kez işaret edebilir.
     Sanal sayesinde fonksiyon çağrısının sonucu dinamik olacaktır. ve çalışma zamanında karar verilecektir.

     Üye fonksiyonu çağırdığımızda yürütme sırasında dinamik bağlantılı bir fonksiyon olduğu için nesnenin gerçek tipini arayacaktır. yürüyecek
  gerçek türü bulmak için kalıtım ağacı aracılığıyla.

     Bir sanal üye işlevine yöntem denir.
     Bir yöntemin tanımı, çözümlemenin dinamik olacağı bir üye işlevdir.

Sanal İşlev Kuralları:

     - Sanal işlevler bir sınıfın üyesi olmalıdır.
     - Sanal işlevler statik üye olamaz.
     - Nesne işaretçileri aracılığıyla erişilir.
     - Başka bir sınıfın arkadaşı olabilirler.
     - Kullanılmasa bile temel sınıfta sanal bir işlev tanımlanmalıdır.
     - Temel sınıfın ve tüm türetilmiş sınıfların sanal işlevinin prototipleri aynı olmalıdır. Aynı ada ancak farklı prototiplere sahip iki işlev varsa, C++ bunları aşırı yüklenmiş işlevler olarak kabul eder.
     - Sanal bir kurucumuz olamaz ama sanal bir yıkıcımız olabilir.

 * @return int
 */
int	main()
{
// This area for PDF's test.
	std::cout << GREEN "*********** Default AAnimal Test Area ************" END\
		<< std::flush << std::endl;
	const AAnimal	*j = new Dog();
	const AAnimal	*i = new Cat();
	std::cout << "-------- Dog and Cat Created! ------"\
		<< std::flush << std::endl << std::endl;
	std::cout << "\n-------- AAnimals Destroying! ------"\
		<< std::flush << std::endl;
	delete j;// Should not create leak
	delete i;
	// std::cout << GREEN "Leaks: ";
	std::cout << B_GREEN "Leaks: " << std::flush;// Eger buraya std::flush yazmazsam "Leaks: " 'i terminalde calistirdigimiz leaks'ten sonra yazdiyor ve bir isime yaramiyor... :)
	system("leaks AAnimalBrain | grep 'leaked bytes'");
	std::cout << END << std::flush;
	std::cout << GREEN "************************************************" END\
		<< std::flush << std::endl;

// This area for allocating memory for inherited classes.
	JustSelfTestForAllocation();

// This area for test all class with loop.
	std::cout << "[[[[[[[[[Loop Started!]]]]]]]]]]]" << std::flush << std::endl;
	JustSelfTestForAllocationLoop();
	return (0);
}