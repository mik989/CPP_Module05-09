#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>


void moltiplica(int n)
{
    std::cout << "Num * 2 is " << n * 2 << std::endl;
}

template <typename T, typename F>
void iter(T *add, int len, F myFunction)
{
    for (int i = 0; i < len; i++)
    {
        myFunction(add[i]);
    }
}

#endif
