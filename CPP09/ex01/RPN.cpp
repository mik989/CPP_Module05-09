#include "RPN.hpp"

RPN::RPN(std::string input) : _input(input) {}
RPN::~RPN() {}
void RPN::fillStack()
{
    for (size_t i = 0; i < _input.length(); i++)
    {
        if (_input[i] == ' ')
            continue;
        if (isdigit(_input[i]))
        {
            while (isdigit(_input[i]))
            {
                if(_input[i] == ' ')
                    break;
                _data.push_back(std::string(1, _input[i]));
                i++;
            }
            i--;
        }
        else
        {
            std::string operaThor(1, _input[i]);
            _data.push_back(operaThor);
        }
    }
    // for (size_t i = 0; i < _data.size(); i++)
    // {
    //     std::cout << _data[i];
    // }
    std::cout << std::endl;
    std::cout << "Risultato = ";
    // std::cout << std::endl;
}

void RPN::calculaThor()
{
    //if (line.find('|') == std::string::npos)
    std::string result;
    for (std::vector<std::string>::iterator it = _data.begin(); it != _data.end(); ++it)
    {  
        if (*it == "+" || *it == "-" || *it == "*" || *it == "/")
        {
            std::string operaThor = *it;
            std::string number1 = *(it - 2);
            std::string number2 = *(it - 1);
            if (operaThor == "+")
                result = std::to_string(std::stoi(number1) + std::stoi(number2));
            else if (operaThor == "-")
                result = std::to_string(std::stoi(number1) - std::stoi(number2));
            else if (operaThor == "*")
                result = std::to_string(std::stoi(number1) * std::stoi(number2));
            else if (operaThor == "/")
                result = std::to_string(std::stoi(number1) / std::stoi(number2));
            _data.erase(it - 2, it + 1);
            _data.insert(it - 2, result);
            it = _data.begin();
        }
    }
    std::cout << result << std::endl;
    // for (size_t i = 0; i < _data.size(); i++)
    // {
    //     std::cout << _data[i] << std::endl;
    // }

}