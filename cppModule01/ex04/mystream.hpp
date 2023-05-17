#ifndef MYSTREAM_H
#define MYSTREAM_H

#include <iostream>
#include <string>
#include <fstream>

class myStream
{
    std::string text;
    std::string filename;
    public:
        myStream(char*);
        ~myStream();
        std::string getText();
        void replace(char*,char*);
};


#endif