#include "PmergeMe.hpp"

PmergeMe::PmergeMe(std::string **strlist) : _strlist(strlist)
{

}

PmergeMe::~PmergeMe()
{

}

void PmergeMe::createList()
{
    if(this->_strlist == NULL)
    {
        std::cout << "Error: strlist is NULL" << std::endl;
        return;
    }
    // conto gli argomenti
    int ac = 0;
    while(this->_strlist[ac] != NULL)
        ac++;
    if(ac < 1)
    {
        std::cout << "Error: strlist is empty" << std::endl;
        return;
    }
    std::string argument = "";
    if (ac >= 2)
    {
        argument = this->_strlist[1];
    }
    int num = 0;
    if (ac == 1)
    {
        int min, max;
        // Definisci il pattern regolare con gruppi di cattura per i valori numerici
        std::string pattern = R"(shuf -i (\d+)-(\d+) -n (\d+) \| tr "\\n" " ")";

        // Crea l'oggetto std::regex
        std::regex regexPattern(pattern);

        // Confronta l'argomento con il pattern regolare e estrai i valori numerici
        std::smatch matches;
        if (std::regex_match(argument, matches, regexPattern)) 
        {
            // Estrai i valori numerici dai gruppi di cattura
            min = std::stoi(matches[1]);
            max = std::stoi(matches[2]);
            num = std::stoi(matches[3]);

            // Effettua ulteriori controlli sui valori numerici
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
    }
    else
    {
        std::string line;
        std::istringstream iss(argument);
        while (std::getline(iss, line, ' ')) 
            num++;
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
    std::string delimiter = " ";
    size_t pos = 0;
    std::string token;

    while ((pos = input.find(delimiter)) != std::string::npos) 
    {
        token = input.substr(0, pos);
        input.erase(0, pos + delimiter.length());

        try 
        {
            // Converti il numero in intero e inseriscilo nella lista
            this->_lst.push_back(std::stoi(token));
        } 
        catch (const std::invalid_argument& e) 
        {
            std::cout << "Errore: Numero non valido (1): " << token << std::endl;
            return;
        }
    }
    // L'ultimo numero rimanente dopo l'ultimo spazio
    try 
    {
        if(input != "" && input != "\n" && input != "\0" && input != " ")
            this->_lst.push_back(std::stoi(input));
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cout << "Errore: Numero non valido (2): " << input << std::endl;
        return;
    }
    std::cout << std::endl;
    if (this->_lst.size() != num) 
    {
        std::cout << "la lista e' grande cosi: " << this->_lst.size() << std::endl;
        std::cerr << "Error: Failed to read all numbers from the command output.\n";
        return;
    }
}

void PmergeMe::merge_sort(std::list<int>& lst) 
{
    if (lst.size() <= 1) {
        return;
    }
    std::list<int> left, right;
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
    std::cout << "Before: ";
    for (auto n : this->_lst) 
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    merge_sort(this->_lst);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "After: ";
    for (auto n : this->_lst) 
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    auto time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << "Time to process a range of " << this->_lst.size() << " elements with std::list: " << time.count() << " us" << std::endl;
}