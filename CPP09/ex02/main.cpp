#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    PmergeMe pmm(ac, av);
    pmm.createList();
    pmm.sortList();
    return 0;
}
