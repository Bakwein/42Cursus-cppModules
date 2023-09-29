#include "ScalarConverter.hpp"

/*

The static_cast operator in C++ is a unary operator that casts an expression to a different type. It is a compile-time cast, which means that the conversion is checked at compile time and an error will be generated if the conversion is not possible.

The syntax for the static_cast operator is:

static_cast<target_type>(expression)
where target_type is the type to which the expression is being cast and expression is the expression that is being cast.

The static_cast operator can be used to cast between many different types, including:

Integral types (such as int, char, and long)
Floating-point types (such as float and double)
Pointer types
Reference types
User-defined types
The static_cast operator can also be used to cast between void and any other type.

The static_cast operator is a safe cast, which means that it will not cause any data loss or corruption. However, it is important to use the static_cast operator carefully, as it can be used to cast between types that are not compatible. For example, it is not possible to cast a pointer to a base class to a pointer to a derived class, unless the derived class is explicitly convertible to the base class.

Here are some examples of how the static_cast operator can be used:

int x = 10;
float y = static_cast<float>(x); // Converts x to a float

char *str = "Hello, world!";
void *ptr = static_cast<void *>(str); // Converts str to a void pointer

MyClass *obj = new MyClass();
MyDerivedClass *derived_obj = static_cast<MyDerivedClass *>(obj); // This is safe because MyDerivedClass is explicitly convertible to MyClass

The static_cast operator is one of the four casting operators in C++. The other three casting operators are:

const_cast
dynamic_cast
reinterpret_cast
The const_cast operator is used to cast away const or volatile qualifiers.

The dynamic_cast operator is used to cast between polymorphic types.

The reinterpret_cast operator is used to cast between any two types, regardless of their size or alignment.
*/

void ScalarConverter::convert(std::string &str)
{
    long long intValue = 0;
    float floatValue= 0.0f;
    double doubleValue = 0.0;
    char charValue = 0;

    int (*p[6])(std::string &str) = {&control,&isInt,&isDouble,&isFloat,&isChar,&dif};
    for (int i = 0; i < 6 ; i++)
    {
        if(p[i](str))
        {
            if(i == 1)
            {
                //std::cout << "INT" << std::endl;
                double test_double = std::atof(str.c_str());
                if(test_double > INT_MAX || test_double <INT_MIN)
                {
                    std::cout << YELLOW << "INT_MAX - INT_MIN error!" << RESET << std::endl;
                    exit(0);
                }
                intValue = std::atoi(str.c_str());
                printChar(intValue);
                printInt(intValue);
                printFloat(intValue);
                printDouble(intValue);
            }
            else if(i == 2)
            {
                //std::cout << "DOUBLE" << std::endl;
                doubleValue = atof(str.c_str());
                printChar(doubleValue);
                printInt(doubleValue);
                printFloat(doubleValue);
                printDouble(doubleValue);
            }
            else if(i == 3)
            {
                //std::cout << "FLOAT" << std::endl;
                floatValue = atof(str.c_str());
                printChar(floatValue);
                printInt(floatValue);
                printFloat(floatValue);
                printDouble(floatValue);
            }
            else if(i == 4)
            {
                //std::cout << "CHAR" << std::endl;
                charValue = str[0];
                printChar(charValue);
                printInt(charValue);
                printFloat(static_cast<int>(charValue));
                printDouble(static_cast<int>(charValue));
            }
            break;
        }
    }
}

int ScalarConverter::control(std::string &str)
{
    if(str == "inf" || str == "inff" || str == "infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "inff" << std::endl;
        std::cout << "double: " << "inf" << std::endl;
        exit (0);
    }
    else if(str == "-inf" || str == "-inff" || str == "-infl")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << "-inff" << std::endl;
        std::cout << "double: " << "-inf" << std::endl;
        exit(0);
    }
    return (0);
}

int ScalarConverter::isChar(std::string &str)
{
    int len = str.length();
    if(len == 1 && isprint(str[0]))
        return (1);
    return (0);
}


int ScalarConverter::isFloat(std::string &str)
{
    if(str[str.length()-1] != 'f' 
    || str[str.length()-1] == '.'  // cuz of f
    || str.rfind(".") != str.find(".")) // multi .
    {
        return(0);
    }
    else if(str[str.length()-2] == '.')
    {
        int id = 0;
        while(str[id] <= 32)
        {
            id++;
        }
        if(str[id] == '-' || str[id] == '+')
        {
            id++;
        }
        while(str[id] >= '0' && str[id] <= '9')
        {
            id++;
        }
        if(str[id] == '.' || str[id+1] == 'f')
            return (1);
        return (0);
    }
    else if(str[0] == '.' || ((str[0] == '+' || str[0] == '-') && str[1] == '.'))
    {
        int id2 = 0;
        if(str[id2] == '+' || str[id2] == '-')
        {
            id2++;
        }
        if(str[id2] == '.')
        {
            id2++;
        }
        while(str[id2] >= '0' && str[id2] <= '9')
        {
            id2++;
        }
        if(str[id2] == 'f')
            id2++;
        if(id2 == int(str.length()))
            return(1);
        return (0);
    }
    int i = 0;
    int len = str.length();
    while(str[i] <= 32)
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    while((str[i] >= '0' && str[i] <= '9')  || str[i] == '.' || str[i] == 'e' || str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    if(str[i] == 'f')
        i++;
    if(i == len)
        return(1);
    return (0);
}

int ScalarConverter::isDouble(std::string &str)
{
    if(str.rfind(".") != str.find(".")) // multible .
    {
        return(0);
    }
    else if(str[str.length()-1] == '.') //1.3
    {
        int id = 0;
        while(str[id] <= 32)
        {
            id++;
        }
        if(str[id] == '-' || str[id] == '+')
        {
            id++;
        }
        while(str[id] >= '0' && str[id] <= '9')
        {
            id++;
        }
        if(str[id] == '.')
            return(1);
        return (0);
        
    }
    else if(str[0] == '.' || ((str[0] == '+' || str[0] == '-') && str[1] == '.'))
    {
        int id2 = 0;
        if(str[id2] == '+' || str[id2] == '-')
        {
            id2++;
        }
        if(str[id2] == '.')
        {
            id2++;
        }
        while(str[id2] >= '0' && str[id2] <= '9')
        {
            id2++;
        }
        if(id2 == int(str.length()))
            return(1);
        return (0);
    }
    int i = 0;
    int len = str.length();
    while(str[i] <= 32)
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    while((str[i] >= '0' && str[i] <= '9')  || str[i] == '.' || str[i] == 'e' || str[i] == '+' || str[i] == '-' )
    {
        i++;
    }
    if(i == len)
        return(1);
    return (0);
}

int ScalarConverter::isInt(std::string &str)
{   
    int i = 0;
    int len = str.length();
    while(str[i] <= 32)
    {
        i++;
    }
    if(str[i] == '-' || str[i] == '+')
    {
        i++;
    }
    while(str[i] >= '0' && str[i] <= '9')
    {
        i++;
    }
    if(i == len)
        return(1);
    return (0);
}


int ScalarConverter::dif(std::string &str)
{
    (void)str; //for flags
    std::cout << "char: infinity" << std::endl;
    std::cout << "int: infinity" << std::endl;
    std::cout << "float: infinity" << std::endl;
    std::cout << "double: infinity" << std::endl;
    exit(0);
}
