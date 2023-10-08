#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iostream>


template<typename T>
void    easyfind(T a,int i)
{
    if(a.empty())
    {
        std::cout << "container is empty!" << std::endl;
        return;
    }
    if(std::find(a.begin(),a.end(),i) != a.end())
    {
        std::cout << "container has " << i << " value!" << std::endl;
    }    
    else
    {
        std::cout << i << " not found!" << std::endl;
    }
}




/*
İlk kolay egzersiz sağ ayakla başlamanın yoludur.
T tipini kabul eden bir easyfind fonksiyon şablonu yazın. İki parametre alır.
Birincisi T tipinde, ikincisi ise bir tam sayıdır.
T'nin tamsayılardan oluşan bir kapsayıcı olduğunu varsayarsak, bu işlevin ilk geçtiği yeri bulması gerekir
ikinci parametrenin birinci parametredeki değeri.
Herhangi bir olay bulunamazsa, bir istisna oluşturabilir veya bir hata değeri döndürebilirsiniz.
sizin seçiminiz. İlhama ihtiyacınız varsa standart kapların nasıl davrandığını analiz edin.
Elbette her şeyin beklendiği gibi çalıştığından emin olmak için kendi testlerinizi uygulayın ve teslim edin.
İlişkisel kapsayıcıları kullanmanıza gerek yoktur.
*/




#endif