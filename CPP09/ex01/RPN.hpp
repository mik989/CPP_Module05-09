#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>
#include <cstdlib>

class RPN 
{
    public:
        RPN(std::string input);
        ~RPN();
        void fillStack();
        void calculaThor();
    private:
        std::vector<std::string> _data;
        std::string _input;
};

#endif