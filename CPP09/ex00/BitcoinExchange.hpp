#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

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

class BitcoinExchange 
{
    public:
        BitcoinExchange(std::string filename);
        float getInput(std::string input_txt);
        float readData(); 
        bool check_data(std::string data);
    private:
        std::map<std::string, float> _dataMap;
        std::string _fileName;
};

#endif