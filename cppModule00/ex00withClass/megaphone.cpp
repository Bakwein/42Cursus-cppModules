#include <iostream>

using std:: cout;
using std:: cin;
using std:: endl;

class mega
{
    char a;
    public:
        char get();
        void set(int);
};


char mega::get(){return a;}
void mega::set(int a)
{
    if(a >= 97 && a <= 122)
        a -= 32;
    this->a = a;
}

int main(int argc,char **argv)
{
    mega m1;

    if(argc == 1)
        cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else if(argc >= 1)
    {
        int y = 1;
        while(argv[y])
        {
            int x = 0;
            while(argv[y][x])
            {
                m1.set(argv[y][x]);
                cout << m1.get();
                x++;
            }
            y++;
        }
    }
    cout << endl;
    
    return 0;
}