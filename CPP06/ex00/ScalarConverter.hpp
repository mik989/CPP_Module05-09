#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <iomanip>
#include <typeinfo>

class ScalarConverter
{
    public:

        static void     convert(std::string str);

        static void     convertToChar(char charVal);
        static void     convertToInt(int intVal);
        static void     convertToFloat(float floatVal);
        static void     convertToDouble(double doubleVal);
        static bool     isFloatingPointNumber(std::string str);

        static void     putchar(char c);
        static void     putdouble(std::string c);
        static void     putdigit(std::string c);
        static int      ft_checkisnumber(std::string av);
};

#endif