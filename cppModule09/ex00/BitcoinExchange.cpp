#include "BitcoinExchange.hpp"
#include <iostream>


BitcoinExchange::BitcoinExchange()
{
    std::cout << "BitcoinExchange default const." << std::endl;
}

BitcoinExchange::BitcoinExchange(char *av)
{
    this->av_ = av;
    //std::cout << "BitcoinExchange char* const." << std::endl;
}

void BitcoinExchange::run()
{
    this->readCSV();
    this->output();
}

void BitcoinExchange::readCSV()
{   
    //std::cout << PURPLE << "readCSV" << RESET << std::endl;
    file_csv.open(CSV);
    if (!file_csv.is_open())
        throw FileOpenProblem();
    std::string line;
    std::string date;
    std::string price;
    std::string year;
    std::string month;
    std::string day;
    std::string v = ",";
    int i = 0;
    //std::string sınıfındaki find() yöntemi, belirtilen dizgiyi dize içinde arar. Dizgi bulunamazsa, find() yöntemi std::string::npos değerini döndürür.
    while (std::getline(file_csv, line))
    {
        if(line.empty() || line.find(v) == std::string::npos)
            throw FileSyntaxError();
        date = line.substr(0, line.find(v));
        price = line.substr(line.find(v) + 1, line.length());
        if(date.empty() || price.empty())
            throw FileSyntaxError();
        if (i == 0)
        {
            if(date != "date" || price != "exchange_rate")
                throw FileSyntaxError();
            i++;
            continue;
        }
        //date control
        int count = std::count(date.begin(), date.end(), '-');
        if(count != 2)
            throw FileSyntaxError();
        
        year = date.substr(0, date.find("-"));
        std::string forM = date.substr(date.find("-")+ 1, date.length());
        month = forM.substr(0, forM.find("-"));
        std::string forD = forM.substr(forM.find("-")+ 1, forM.length());
        day = forD.substr(forD.find("-") + 1, forD.length());
        if(year.length() != 4 || month.length() !=2 || day.length() != 2)
        {
            throw FileSyntaxError();
        }
        for(int i = 0;i < int(year.length());i++)
        {
            if(!isdigit(year[i]))
                throw FileSyntaxError();
        }
        for(int i = 0;i < int(month.length());i++)
        {
            if(!isdigit(month[i]))
                throw FileSyntaxError();
        }
        for(int i = 0;i < int(day.length());i++)
        {
            if(!isdigit(day[i]))
                throw FileSyntaxError();
        }
        //span control
        int y = std::stoi(year);
        int m = std::stoi(month);
        int d = std::stoi(day);
        if(y>2023 || m>12 || m <1)
        {
            throw FileSyntaxError();
        }
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            if(d > 31 || d < 1)
                throw FileSyntaxError();
        }
        else if(m == 4 || m == 6 || m == 9 || m == 11)
        {
            if(d > 30 || d < 1)
                throw FileSyntaxError();
        }
        else if(m == 2)
        {  
            // leap year
            if(y % 4 == 0)
            {
                if(y % 100 == 0)
                {
                    if(y % 400 == 0)
                    {
                        if(d > 29 || d < 1)
                            throw FileSyntaxError();
                    }
                    else
                    {
                        if(d > 28 || d < 1)
                            throw FileSyntaxError();
                    }
                }
                else
                {
                    if(d > 29 || d < 1)
                        throw FileSyntaxError();
                }
            }
            {
                if(d > 28 || d < 1)
                    throw FileSyntaxError();
            }
        }
        //price control
        float d_ = std::stof(price);
        map_csv.insert(std::pair<std::string, float>(date, d_));
    }

}

void BitcoinExchange::output()
{
    //std::cout << CYAN << "output" << RESET << std::endl;
    file_input.open(this->getAv());
    if (!file_input.is_open())
        throw FileOpenProblem();
    std::string line;
    std::string date;
    std::string price;
    std::string year;
    std::string month;
    std::string day;
    std::string v = "|";
    int i = 0;
    while(std::getline(file_input, line))
    {
        if(line.empty())
        {
            std::cout << "Error: line is empty" << std::endl;
            continue;
        }
        if(line.find(v) == std::string::npos)
        {
            std::cout << "Error: bad input => "<< line << std::endl;
            continue;
        }
        date = line.substr(0, line.find(v)-1);
        price = line.substr(line.find(v) + 2, line.length());
        if(date.empty())
        {
            std::cout << "Error: bad input - date is empty => "<< line << std::endl;
            continue;
        }
        else if(price.empty())
        {
            std::cout << "Error: bad input - prize is empty => "<< line << std::endl;
            continue;
        }
        if (i == 0)
        {
            if(date != "date" || price != "value")
            {
                throw FileSyntaxError();
            }
            i++;
            continue;
        }
        //date kontrol
        std::string temp_date = date;
        int count = std::count(date.begin(), date.end(), '-');
        if(count != 2)
        {
            std::cout << "Error: bad input  => "<< line << std::endl;
            continue;
        }
        year = date.substr(0, date.find("-"));
        std::string forM = date.substr(date.find("-")+ 1, date.length());
        month = forM.substr(0, forM.find("-"));
        std::string forD = forM.substr(forM.find("-")+ 1, forM.length());
        day = forD.substr(forD.find("-") + 1, forD.length());
        if(year.length() != 4 || month.length() !=2 || day.length() != 2)
        {
            std::cout << "Error: bad input  => "<< line << std::endl;
            continue;
        }
        for(int i = 0;i < int(year.length());i++)
        {
            if(!isdigit(year[i]))
            {
                std::cout << "Error: bad input  => "<< line << std::endl;
                continue;
            }
        }
        for(int i = 0;i < int(month.length());i++)
        {
            if(!isdigit(month[i]))
            {
                std::cout << "Error: bad input  => "<< line << std::endl;
                continue;
            }
        }
        for(int i = 0;i < int(day.length());i++)
        {
            if(!isdigit(day[i]))
            {
                std::cout << "Error: bad input  => "<< line << std::endl;
                continue;
            }
        }
        //span control
        int y = std::stoi(year);
        int m = std::stoi(month);
        int d = std::stoi(day);
        if(y>2023 || m>12 || m <1)
        {
            std::cout << "Error: bad input  => "<< line << std::endl;
            continue;
        }
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            if(d > 31 || d < 1)
            {
                std::cout << "Error: bad input  => "<< line << std::endl;
                continue;
            }
        }
        else if(m == 4 || m == 6 || m == 9 || m == 11)
        {
            if(d > 30 || d < 1)
            {
                std::cout << "Error: bad input  => "<< line << std::endl;
                continue;
            }
        }
        else if(m == 2)
        {  
            // leap year
            if(y % 4 == 0)
            {
                if(y % 100 == 0)
                {
                    if(y % 400 == 0)
                    {
                        if(d > 29 || d < 1)
                        {
                            std::cout << "Error: bad input  => "<< line << std::endl;
                            continue;
                        }
                    }
                    else
                    {
                        if(d > 28 || d < 1)
                        {
                            std::cout << "Error: bad input  => "<< line << std::endl;
                            continue;
                        }
                    }
                }
                else
                {
                    if(d > 29 || d < 1)
                    {
                        std::cout << "Error: bad input  => "<< line << std::endl;
                        continue;   
                    }
                }
            }
            {
                if(d > 28 || d < 1)
                {
                    std::cout << "Error: bad input  => "<< line << std::endl;
                    continue;
                }
            }
        }
        // PRICE CONTROL
        float d_ = std::stof(price);
        float temp_price = d_;
        if(d_ < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if(d_ > 1000)
        {
            std::cout << "Error: too large number." << std::endl;
            continue;
        }

        /*std::map<std::string, float>::iterator it2 = this->map_csv.find(date); // tam tarihi bulur
        if(it2 != this->map_csv.end())
        {
            std::cout << date << " => " << d_ << " = " << it2->second * d_ << std::endl;
            continue;
        }*/

        //date ->temp_date
        //price -> temp_price

        std::map<std::string,float>::iterator it = this->map_csv.lower_bound(temp_date); // lower bound kendisine ve altına bakar
        if(it == this->map_csv.end())// hic dusuk bulamadi
        {
            --it;
        }
        else if(it == this->map_csv.begin() && temp_date < it->first) // baslangici gosterip ve baslangictaki de date'den buyukse
        {
            std::cout << "Error: no data for this date." << std::endl;
            continue;
        }
        else if(date < it->first) // date is between two dates in this->_data.
        {
            --it;
        }
        std::cout << temp_date << " => " << temp_price << " = " << it->second * temp_price << std::endl;
    }

}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &rhs)
{
    std::cout << "BitcoinExchange copy const." << std::endl;
    av_ = rhs.getAv();
    *this = rhs;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& rhs)
{
    std::cout << "BitcoinExchange operator=." << std::endl;
    if (this != &rhs)
    {
        this->av_ = rhs.getAv();
    }
    return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
    //std::cout << "BitcoinExchange destructor." << std::endl;
}

void BitcoinExchange::printMap(std::map<std::string,float> map)
{
    for (std::map<std::string,float>::iterator it=map.begin(); it!=map.end(); ++it)
        std::cout << it->first << " => " << it->second << '\n';

    std::cout << "map size: " << map.size() << std::endl;    
}