#include "Data.hpp"

/*
struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};
*/
/*
class A
{
    public:
        void za()
        {
            std::cout << "zaaa" << std::endl;
        }
};

class B
{
    public:
        void random()
        {
            std::cout << "sadhasdhadshas" << std::endl;
        }
};
*/


int main()
{
    {
        Data *d = new Data; 
        std::cout << d << std::endl;
        d->s1 = "sefaT!";
        d->num = 41;

        std::cout << std::endl;
        uintptr_t ui = serialize(d);
        std::cout << ui << std::endl;
        Data *ptr = deserialize(ui);
        std::cout << ptr << std::endl;
        std::cout << "ptr->num: " << ptr->num << std::endl;
        std::cout << "ptr->s1: " << ptr->s1 << std::endl;

        //free all allocated memory
        delete d;
        //delete ptr;
    }

    std::cout << "\n\n";

    {
        int sefa = 90;
        int *p_sefa = &sefa;

        char *p_sefa_char = reinterpret_cast<char*>(p_sefa);
        std::cout << *p_sefa_char << std::endl;
        //char sefa_char = reinterpret_cast<char>(sefa); NOT    ALLOWED

        int *p_sefa_int = reinterpret_cast<int*>(p_sefa);
        std::cout << *p_sefa_int << std::endl;

        int sefa_int = reinterpret_cast<int>(*p_sefa_int);
        std::cout << sefa_int << std::endl;

        //char sefa_char = reinterpret_cast<char>(*p_sefa_int);     NOT ALLOWED

        //long sefa_long = reinterpret_cast<long>(*p_sefa_int);     INT POINTER TO LONG NOT ALLOWED
        //std::cout << sefa_long << std::endl;

        //long sefa_long = reinterpret_cast<long>(sefa); INT TO     LONG NOT ALLOWED
        //std::cout << sefa_long << std::endl;

        long sefa_long2 = reinterpret_cast<long>(p_sefa); //    pointer adress to long 
        std::cout << sefa_long2 << std::endl;

        std::cout << "\n\n";
        int *p = new int(84);
        char *c_p = reinterpret_cast<char*>(p);
        std::cout << "*p: " <<*p << std::endl;
        std::cout << "*c_p: " << *c_p << std::endl;
        std::cout << "p: " << p << std::endl;
        std::cout << "c_p: " << c_p << std::endl;

        int *new_ptr = reinterpret_cast<int*>(c_p);
        std::cout << "*new_ptr: " << *new_ptr << std::endl;
        std::cout << "new_ptr: " << new_ptr << std::endl;

        //int xd = reinterpret_cast<int>(new_ptr); NOT ALLOWED
        std::cout << sizeof(int) << " " << sizeof(long) << " " << sizeof(int*) << std::endl;

        long xdl = reinterpret_cast<long>(new_ptr); // NO PROBLEM
        std::cout << "xdl: " << xdl << std::endl;

        delete p;
    }
    /*
    std::cout << "\n\n";
    // WORKING WITH BITS
    {
        mystruct s;
        s.x = 14;
        s.y = 52;
        s.c = 'a';
        s.b = true;

        std::cout << "struct size: " << sizeof(s) << std::endl;

        int *p = reinterpret_cast<int*>(&s);
        std::cout << *p << std::endl;

        p++;
        std::cout << *p << std::endl;

        p++;
        char *c_p = reinterpret_cast<char*>(p);
        std::cout << *c_p << std::endl;

        c_p++;
        bool *b_p = reinterpret_cast<bool*>(c_p);
        std::cout << *b_p << std::endl;
        
    }
    */
    /*
    std::cout << "\n\n";
    {
        B *b = new B;
        A *a = reinterpret_cast<A*>(b);
        a->za();

        delete b;
    }
    */
    return 0;
}