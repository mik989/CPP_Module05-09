#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char **strlist) : _ac(ac), _strlist(strlist)
{

}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::createList()
{
    // conto gli argomenti
    if(_ac < 2)
    {
        std::cout << "Usage: ./PmergeMe.shuf -i min-max -n num" << std::endl;
        return;
    }
    else if(_ac == 2)
    {
        std::string argument = _strlist[1];
        int min, max, num;
        std::string pattern = R"(shuf -i (\d+)-(\d+) -n (\d+) \| tr "\\n" " ")";

        std::regex regexPattern(pattern);

        std::smatch matches;
        if (std::regex_match(argument, matches, regexPattern)) 
        {
            min = std::stoi(matches[1]);
            max = std::stoi(matches[2]);
            num = std::stoi(matches[3]);

            if (min < max && num > 0) 
            {
                std::cout << "L'argomento inserito è nel formato corretto." << std::endl;
                std::cout << "min: " << min << ", max: " << max << ", num: " << num << std::endl;
            } 
            else 
            {
                std::cout << "L'argomento inserito contiene valori non validi." << std::endl;
            }
        } 
        else 
        {
            std::cout << "L'argomento inserito non rispetta il formato richiesto." << std::endl;
        } 

        FILE* pipe = popen(argument.c_str(), "r");

        char buffer[128];
        std::string input;
        while (!feof(pipe)) 
        {
            if (fgets(buffer, 128, pipe) != NULL)
                input += buffer;
        }
        pclose(pipe);

        std::istringstream iss(input);
        int number;
        while (iss >> number) 
        {
            this->_lst.push_back(number);
            this->_lst1.push_back(number);
        }
        // std::string delimiter = " ";
        // size_t pos = 0;
        // std::string token;

        // while ((pos = input.find(delimiter)) != std::string::npos) 
        // {
        //     token = input.substr(0, pos);
        //     input.erase(0, pos + delimiter.length());
        //     try 
        //     {
        //         this->_lst.push_back(std::stoi(token));
        //         this->_lst1.push_back(std::stoi(token));
        //     } 
        //     catch (const std::invalid_argument& e) 
        //     {
        //         std::cout << "Errore: Numero non valido (1): " << token << std::endl;
        //         return;
        //     }
        // }
        // try 
        // {
        //     if(input != "" && input != "\n" && input != "\0" && input != " ")
        //     {
        //         this->_lst.push_back(std::stoi(input));
        //         this->_lst1.push_back(std::stoi(input));
        //     }
        // } 
        // catch (const std::invalid_argument& e) 
        // {
        //     std::cout << "Errore: Numero non valido (2): " << input << std::endl;
        //     return;
        // }
        std::cout << std::endl;
        if (this->_lst.size() != num) 
        {
            std::cout << "la lista e' grande cosi: " << this->_lst.size() << std::endl;
            std::cerr << "Error: Failed to read all numbers from the command output.\n";
            return;
        }
        if (this->_lst1.size() != num) 
        {
            std::cout << "la lista 1 e' grande cosi: " << this->_lst1.size() << std::endl;
            std::cerr << "Error: Failed to read all numbers from the command output.\n";
            return;
        }
    }
    else if (_ac > 2) 
    {
        for(int i = 1; i < _ac; i++)
        {
            try 
            {
                this->_lst.push_back(std::stoi(_strlist[i]));
                this->_lst1.push_back(std::stoi(_strlist[i]));
            } 
            catch (const std::invalid_argument& e) 
            {
                std::cout << "Errore: Numero non valido (3): " << _strlist[i] << std::endl;
                return;
            }
        }
    }
}

template <typename T>
void PmergeMe::merge_sort(T& lst) 
{
    if (lst.size() <= 1) {
        return;
    }
    T left, right;
    auto middle_it = std::next(lst.begin(), lst.size() / 2);
    std::move(lst.begin(), middle_it, std::back_inserter(left));
    std::move(middle_it, lst.end(), std::back_inserter(right));

    merge_sort(left);
    merge_sort(right);
    lst.clear();
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(lst));
}

void PmergeMe::sortList()
{
    std::cout << "Before List : ";
    for (auto n : this->_lst) 
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(this->_lst);
    auto end = std::chrono::high_resolution_clock::now();

    auto start1 = std::chrono::high_resolution_clock::now();
    merge_sort(this->_lst1);
    auto end1 = std::chrono::high_resolution_clock::now();

    std::cout << "After List : ";
    for (auto n : this->_lst) 
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
   
    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    auto time1 = std::chrono::duration_cast<std::chrono::microseconds>(end1 - start1);
    std::cout << "Time to process a range of " << this->_lst.size() << " elements with std::list: " << time.count() << " us" << std::endl;
    std::cout << "Time to process a range of " << this->_lst1.size() << " elements with std::deque: " << time1.count() << " us" << std::endl;
}