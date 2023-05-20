/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stunca <stunca@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:15:03 by stunca            #+#    #+#             */
/*   Updated: 2023/05/20 14:51:43 by stunca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

//::->Scope oparetor
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