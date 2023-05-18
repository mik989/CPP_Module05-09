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
#include <deque>

class PmergeMe
{
    public:
        PmergeMe(int ac, char **strlist);
        ~PmergeMe();
        void sortList();
        void createList();
        template <typename T>
        void merge_sort(T& lst); 
    private:
        std::list<int> _lst;
        std::deque<int> _lst1;
        char **_strlist;
        int _ac;
       
};

#endif