#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        try
        {
             Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("robotomy request",         "Bender");
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << '\n';
        }
        //system("leaks bureaucrat4");
    }
    
    std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

    {
        try
        {
            Intern someRandomIntern;
            AForm* rrf;
            rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        //system("leaks bureaucrat4");
    }
   std::cout << BLUE <<"----------------------------------------------" << RESET <<std::endl;

   {
        try
        {   
            Bureaucrat bur1("sefaT",1);
            Intern intern1;
            AForm *rff = intern1.makeForm("ShrubberyCreationForm", "second page");
            std::cout << *rff;
            bur1.signForm(*rff);
            bur1.executeForm(*rff);
            std::cout << "\n";

            Bureaucrat bur2("ali",1);
            Intern intern2;
            AForm *rff2 = intern2.makeForm("PresidentialPardonForm", "third page");
            std::cout << *rff2;
            bur2.signForm(*rff2);
            bur2.executeForm(*rff2);
            std::cout << "\n";

            Bureaucrat bur3("veli",1);
            Intern intern3;
            AForm *rff3 = intern3.makeForm("ShrubberyCreationForm", "fifth page");
            std::cout << *rff3;
            bur3.signForm(*rff3);
            bur3.executeForm(*rff3);
            std::cout << "\n";
        
        }
        catch(const std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
        //system("leaks bureaucrat4");
   }
    //system("leaks bureaucrat4");
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