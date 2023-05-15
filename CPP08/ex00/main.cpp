#include "easyfind.hpp"

#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    std::vector<int> v{1, 2, 3, 42, 5};
    std::cout << easyfind(v, 42) << std::endl;
    return 0;
}