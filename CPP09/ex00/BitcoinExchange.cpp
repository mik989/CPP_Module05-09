#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename) : _fileName(filename)
{
}

bool BitcoinExchange::check_data(std::string data)
{
    if(data.length() != 11)
        return (false);
    if (data[4] != '-' || data[7] != '-')
        return (false);
    if (data[10] != ' ')
        return (false);
    if (!isdigit(data[0]) || !isdigit(data[1]) || !isdigit(data[2]) || !isdigit(data[3]))
        return false;

    if (!isdigit(data[5]) || !isdigit(data[6]) || !isdigit(data[8]) || !isdigit(data[9]))
        return false;

    int year = stoi(data.substr(0, 4));
    int month = stoi(data.substr(5, 2));
    int day = stoi(data.substr(8, 2));
    
    if (month < 1 || month > 12)
        return false;
    
    int daysInMonth = 31;

    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            daysInMonth = 29;
        else
            daysInMonth = 28;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) 
        daysInMonth = 30;    
    if (day < 1 || day > daysInMonth)
        return false;
    return true;
}
float BitcoinExchange::getInput(std::string input_txt)
{
    std::fstream inputFile;
    std::string line;

    inputFile.open(input_txt.c_str(), std::ios::in);
    if (!inputFile)
    {
        std::cout << "The input file could not be opened" << std::endl;
        exit(0);
    }
    getline(inputFile, line);
    while(getline(inputFile, line))
    {
        std::stringstream lineStream(line);
        std::string cell;

        if (line.find('|') == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
        getline(lineStream, cell, '|');
        std::string data = cell;
        if (!check_data(data))
        {
            std::cout << "Error: bad input => " << data << std::endl;     
            continue;
        }
        getline(lineStream, cell);
        float prezzo = std::stof(cell);
        if (prezzo < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if (prezzo > 1000)
        {
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, float>::iterator it = _dataMap.find(data);
        if (it->first == data)
            std::cout << it->first << " => " << prezzo << " = " << (it->second * prezzo) << std::endl;
        else
        {
            it = _dataMap.lower_bound(data);
            if (it != _dataMap.begin())
                --it;
            std::cout << it->first << " => " << prezzo << " = " << (it->second * prezzo) << std::endl;
        }

    }
    return (0);
}
float BitcoinExchange::readData()
{
    std::fstream dataFile;
    std::string line;

    dataFile.open(this->_fileName.c_str(), std::ios::in);
    if (!dataFile)
    {
        std::cout << "The input file could not be opened" << std::endl;
        exit(0);
    } 
    getline(dataFile, line);
    while (getline(dataFile, line))
    {
        std::stringstream lineStream(line);
        std::string cell;

        getline(lineStream, cell, ',');
        std::string data = cell;

        getline(lineStream, cell);
        float prezzo = std::stof(cell);

        this->_dataMap[data] = prezzo;
    }

    dataFile.close();
    // for (auto const& element : this->_dataMap) 
   // {
    // std::cout << "Data: " << element.first << ", Prezzo: " << element.second << std::endl;
    //}
    return (0);
}