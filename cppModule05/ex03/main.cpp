#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
    Intern someRandomIntern;
    AForm* rrf;
    rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    }
    
    std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

    {
            Intern someRandomIntern;
        AForm* rrf;
        rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
    }
   std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

   {
        try
        {
            Intern intern1;
            AForm *rff = intern1.makeForm("ShrubberyCreationForm", "second page");
            std::cout << *rff << std::endl;

            Intern intern2;
            AForm *rff2 = intern2.makeForm("PresidentialPardonForm", "third page");
            std::cout << *rff2 << std::endl;

            Intern intern3;
            AForm *rff3 = intern3.makeForm("ShrubberyCreationForm", "fifth page");
            std::cout << *rff3 << std::endl;
        
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
   }
    
    return (0);
}

/*
    Form doldurmak yeterince can sıkıcı olduğundan bürokratlarımıza sormak zalimlik olur.
bunu tüm gün boyunca yapmak. Neyse ki stajyerler var. Bu alıştırmada şunları uygulamanız gerekir:
Stajyer sınıfı. Stajyerin adı, notu, benzersiz özellikleri yoktur. Tek
Bürokratların önem verdiği şey işlerini yapmalarıdır.
Ancak stajyerin önemli bir kapasitesi vardır: makeForm() işlevi. Alır
iki dize. Bunlardan ilki formun adı, ikincisi ise formun hedefidir.
biçim. Bir Form nesnesine (adı parametre olarak iletilen addır) bir işaretçi döndürür.
hedefi ikinci parametreye başlatılacak.
Şöyle bir şey yazdıracaktır:
Stajyer <form>'u oluşturur
Parametre olarak iletilen form adı mevcut değilse açık bir hata mesajı yazdırın.

if/elseif/else ormanı kullanmak gibi okunamayan ve çirkin çözümlerden kaçınmalısınız. Bu
Değerlendirme sürecinde bu tür şeyler kabul edilmeyecektir. Piscine'de değilsin
(havuz) artık. Her zamanki gibi her şeyin beklendiği gibi çalıştığını test etmeniz gerekiyor.

*/