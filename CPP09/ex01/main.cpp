#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: btc input_file" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    RPN RPN(input);
    RPN.fillStack();
    RPN.calculaThor();
    return 0;
}

