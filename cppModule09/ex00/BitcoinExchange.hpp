#ifndef BITCOIN_H
#define BITCOIN_H

#define CSV "data.csv"
#include <iostream>
#include <fstream>
#include <map>
#include <string>

# define BLACK        "\033[0;30m"
# define RED        "\033[0;31m"
# define GREEN        "\033[0;32m"
# define YELLOW        "\033[0;33m"
# define BLUE        "\033[0;34m"
# define PURPLE        "\033[0;35m"
# define CYAN        "\033[0;36m"
# define WHITE        "\033[0;37m"
# define END        "\033[m"
# define RESET        "\033[0m"
# define B_CYAN         "\033[1;36m"
# define B_BLUE         "\033[1;34m"
# define B_YELLOW     "\033[1;33m"
# define B_GREEN         "\033[1;32m"
# define B_RED         "\033[1;31m"
# define B_RESET         "\033[1m"

class BitcoinExchange
{
    private:
        std::string av_;
    public:
        std::map<std::string,float> map_csv;
        
        void run();
        void readCSV();
        void output();

        BitcoinExchange();
        BitcoinExchange(char *av);
        BitcoinExchange(const BitcoinExchange &rhs);
        ~BitcoinExchange();
        BitcoinExchange& operator=(BitcoinExchange const& rhs);

        //av getter-setter
        std::string getAv()const{return av_;}
        void setAv(std::string a){this->av_ = a;}


        //print map
        void printMap(std::map<std::string,float> map);
        //exceptions

        class argcError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return("Error: could not open file.");
            }
        };

        class FileOpenProblem : public std::exception
        {
            virtual const char* what() const throw()
            {
                return("File could not be opened");
            }
        };

        class FileSyntaxError : public std::exception
        {
            virtual const char* what() const throw()
            {
                return("File syntax error");
            }
        };

        
};


#endif