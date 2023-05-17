#include "mystream.hpp"


// ./loser_sed "filename" "string_to_replace" "replacement_string" 
int main(int argc,char **argv)
{
    if(argc != 4)
    {
        return 0;
    }

    myStream myStr(argv[1]);
    myStr.replace(argv[2],argv[3]);
}