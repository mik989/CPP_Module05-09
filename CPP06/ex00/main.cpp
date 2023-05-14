#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
    if (ac != 2)
    {
        std::cout << "Usage: ./convert [string]" << std::endl;
        return (0);
    }
    std::cout << std::fixed << std::setprecision(10);
    std::string str = av[1];
    ScalarConverter sc;
    sc.convert(str);
    return (0);

}