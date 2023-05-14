#include "ScalarConverter.hpp"

void    ScalarConverter::convert(std::string str)
{
    int i;
    for(i = 0; str[i]; i++)
        ;
    if (i == 1 && !isdigit(str[0]))
        ScalarConverter::putchar(str[0]);
    else if (str == "nan" || str == "nanf" || str == "inf" || str == "inff" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff") 
        ScalarConverter::putdouble(str);
    else if (ft_checkisnumber(str))
        ScalarConverter::putdigit(str);
    else
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
    }    
}

int	ScalarConverter::ft_checkisnumber(std::string av)
{
	int	i = 0;
	int	oper = 0;
	int	isnum = 1;
    int point = 0;
    int fl = 0;
 
	while(av[i])
    {
		if (av[i] == '+' || av[i] == '-')
			oper += 1;
        else if (av[i] == '.')
            point += 1;
        else if (av[i] == 'f' || av[i] == 'F')
        {
            fl += 1;
        }          
		else if (!isdigit(av[i]))
			isnum *= isdigit(av[i]);
        i++;
	}
	if (oper > 1 || !isnum || point > 1 || fl > 1)
		return 0;
    else if (av[i-1] == 'f' || av[i-1] == 'F')
        return 1;
    else if (fl == 0)
        return 1;
    else
        return 0; 
}

void    ScalarConverter::putdigit(std::string c)
{
    double val = std::stod(c);
    char charVal = static_cast<char>(val);
    int intVal = static_cast<int>(val);
    float floatVal = static_cast<float>(val);
    double doubleVal = static_cast<double>(val);
    ScalarConverter::convertToChar(charVal);
    if (!isFloatingPointNumber(c))
        ScalarConverter::convertToInt(intVal);
    else
        std::cout << "int: impossible" << std::endl;
    ScalarConverter::convertToFloat(floatVal);
    ScalarConverter::convertToDouble(doubleVal);
}

void    ScalarConverter::putdouble(std::string c)
{
    std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: impossible" << std::endl;
    double val = std::stod(c);
    float floatVal = static_cast<float>(val);
    double doubleVal = static_cast<double>(val);
    if (c == "nanf" || c == "inff" || c == "+inff" || c == "-inff")
    {
        ScalarConverter::convertToFloat(floatVal);
        std::cout << "double: impossible" << std::endl;
    }
    else if (c == "nan" || c == "inf" || c == "+inf" || c == "-inf")
    {
        ScalarConverter::convertToFloat(floatVal);
        ScalarConverter::convertToDouble(doubleVal);
    }
    else
    {
        ScalarConverter::convertToFloat(floatVal);
        ScalarConverter::convertToDouble(doubleVal);
    }
}

void    ScalarConverter::putchar(char c)
{
    char charVal = static_cast<char>(c);
    int intVal = static_cast<int>(c);
    float floatVal = static_cast<float>(c);
    double doubleVal = static_cast<double>(c);
    ScalarConverter::convertToChar(charVal);
    ScalarConverter::convertToInt(intVal);
    ScalarConverter::convertToFloat(floatVal);
    ScalarConverter::convertToDouble(doubleVal);
}

void    ScalarConverter::convertToChar(char charVal)
{   
    if (charVal >= 32 && charVal <= 126)
    {
        std::cout << "char: " << charVal << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
    }
}

void    ScalarConverter::convertToInt(int intVal)
{
    if (std::isnan(intVal) || std::isinf(intVal))
    {
        std::cout << "int: impossible" << std::endl;
    }
    else if (intVal == -2147483648 || intVal == 2147483647)
    {
         std::cout << "int: impossible" << std::endl;
    }
    else
    {
        std::cout << "int: " << intVal << std::endl;
    }
}

void    ScalarConverter::convertToFloat(float floatVal)
{
    std::cout << "float: " << floatVal << "f" << std::endl;
}

void    ScalarConverter::convertToDouble(double doubleVal)
{
    std::cout << "double: " << doubleVal << std::endl;
}

bool ScalarConverter::isFloatingPointNumber(std::string str) 
{
    try 
    {
        size_t pos = 0;
        std::stod(str, &pos);
        return pos == str.length();
    } 
    catch (...) 
    {
        return false;
    }
}