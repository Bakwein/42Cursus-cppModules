
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        //
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