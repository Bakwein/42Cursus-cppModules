
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

    
    {
        try
        {
            PresidentialPardonForm deneme;
            Bureaucrat b1("bureaucrat", 1);
            PresidentialPardonForm f1("target");

            //b1.signForm(f1);
            b1.executeForm(f1);
        }
        catch(const std::exception& e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
         try
        {
            Bureaucrat b1("bureaucrat", 1);
            PresidentialPardonForm f1("target");

            b1.signForm(f1);
            b1.executeForm(f1);
        }
        catch(const std::exception e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    
    {
        try
        {
            Bureaucrat b1("bureaucrat", 1);
            Bureaucrat b2("bureaucrat2",20);
            Bureaucrat b3("bureaucrat3",20);

            PresidentialPardonForm f1("ppFORM");
            RobotomyRequestForm f2("rrFORM");
            ShrubberyCreationForm f3("scFORM");
            ShrubberyCreationForm f4("sefaT");
            
            std::cout << std::endl;
            b1.signForm(f1);
            b2.signForm(f2);
            b3.signForm(f3);
            b2.signForm(f4);
            std::cout << std::endl;

            b1.executeForm(f1);
            b2.executeForm(f2);
            b3.executeForm(f3);
            b1.executeForm(f4);

        }
        catch(const std::exception &e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
        try
        {
            Bureaucrat b1("sefa",20);
            
            // for testing 
            //Bureaucrat b2("bur2"); // grade problem- default grade is 150
            //Bureaucrat b2("bur2",10); // -> already signed

            Bureaucrat b3("bur3",27);
            
            RobotomyRequestForm f1("form1");
            

            std::cout << std::endl;

            b1.signForm(f1);
            //b2.signForm(f1);
            std::cout << std::endl << std::endl;

        /* forms dont execute if they do not signed
            b3.executeForm(f2);
            std::cout << "deneme" << std::endl;
            RobotomyRequestForm f2("form2");
        */
        }
        catch(const std::exception &e)
        {
            std::cout << B_RED << e.what() << RESET <<std::endl;
        }
    }
    std::cout << BLUE <<"---------------------" << RESET <<std::endl;
    {
        try
        {
            Bureaucrat b1("bur1",5);
            
            //Bureaucrat b1("bur1",20); // signed but not executed
            //Bureaucrat b1("bur1",25);

            //Bureaucrat b1("bur1",26); // not signed

            Bureaucrat b2("bur2",45);


            Bureaucrat b3("bur3",137);

            

            PresidentialPardonForm f1("ppF"); // sign 25, exec 5 
            RobotomyRequestForm f2("rrF"); //  sign 72, exec 45
            ShrubberyCreationForm f3("scF"); // sign 145, exec 137

            b1.signForm(f1);
            b2.signForm(f2);
            b3.signForm(f3);

            b1.executeForm(f1);
            b2.executeForm(f2);
            b3.executeForm(f3);
        }
        catch(const std::exception &e)
        {
            std::cout << B_RED <<e.what() << RESET <<std::endl;
        }
    }
    
    return (0);
}

/*
    Artık temel formlara sahip olduğunuza göre, gerçekten bir şeyler yapan birkaç tane daha yapmanın zamanı geldi.
Her durumda, Form temel sınıfı soyut bir sınıf olmalıdır ve bu nedenle
AForm olarak yeniden adlandırıldı. Formun niteliklerinin gizli kalması gerektiğini ve bu
onlar temel sınıftadırlar.
Aşağıdaki somut sınıfları ekleyin:
• ShrubberyCreationForm: Gerekli notlar: işaret 145, yürütme 137
Çalışma dizininde bir <target>_shrubbery dosyası oluşturun ve ASCII ağaçlarını yazın
içinde.
• RobotomyRequestForm: Gerekli notlar: imza 72, yürütme 45
Bazı delme sesleri çıkarıyor. Ardından <hedef>'in robotize edildiğini bildirir
%50 oranında başarılı bir şekilde. Aksi takdirde robotominin başarısız olduğunu bildirir.
• PresidentialPardonForm: Gerekli notlar: imza 25, yürütme 5
<hedef>'in Zaphod Beeblebrox tarafından affedildiğini bildirir.
Hepsi yapıcılarında yalnızca bir parametre alır: formun hedefi. İçin
örneğin evde çalılık dikmek istiyorsanız "ev".
9
C++ - Modül 05 Tekrarlama ve İstisnalar
Şimdi, executive(Bureaucrat const & executor) const üye işlevini şuraya ekleyin:
temel formu oluşturun ve formun somut eylemini yürütmek için bir işlev uygulayın
sınıflar. Formun imzalandığını ve bürokratın notunun doğru olduğunu kontrol etmelisiniz.
formu çalıştırmaya çalışmak yeterince yüksek. Aksi halde uygun bir istisna atın.
İster her beton sınıfındaki ister temeldeki gereksinimleri kontrol etmek isteyin
class (daha sonra formu çalıştırmak için başka bir işlevi çağırın) size kalmış. Ancak bunun bir yolu
diğerinden daha güzel.
Son olarak, PerformForm(Form const & form) üye fonksiyonunu Bureaucrat'a ekleyin. Formu yürütmeye çalışmalıdır. Başarılı olursa şunun gibi bir şey yazdırın:
<bürokrat> <form>'u idam etti
Değilse, açık bir hata mesajı yazdırın.
Her şeyin beklendiği gibi çalıştığından emin olmak için bazı testler uygulayın ve teslim edin.

*/