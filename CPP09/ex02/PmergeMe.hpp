#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <list>
#include <algorithm>
#include <chrono>
#include <string>
#include <iterator>
#include <sstream>
#include <vector>
#include <regex>
#include <cstdio>

class PmergeMe
{
    public:
        PmergeMe(std::string **strlist);
        ~PmergeMe();
        void sortList();
        void createList();
        void merge_sort(std::list<int>& lst); 
    private:
        std::list<int> _lst;
        std::string **_strlist;
       
};

#endif