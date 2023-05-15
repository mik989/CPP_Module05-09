#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <iostream>

template <typename T>
int easyfind(T &container, int n)
{
    std::vector<int>::iterator it = std::find(container.begin(), container.end(), n);
    if (it == container.end())
        throw std::exception();
    return std::distance(container.begin(), it);
}

#endif