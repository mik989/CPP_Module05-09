#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    std::string *strlist[ac];
    for(int i = 0; i < ac; i++)
    {
        *strlist[i] = av[i];
    }

    PmergeMe pmm(strlist);
    pmm.createList();
    pmm.sortList();

    

    return 0;
}
