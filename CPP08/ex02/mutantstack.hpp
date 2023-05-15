#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <string>
#include<iomanip>
#include<iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        using iterator = typename std::stack<T>::container_type::iterator;
        using const_iterator = typename std::stack<T>::container_type::const_iterator;

        iterator begin()
        {
            return std::stack<T>::c.begin();
        }

        iterator end()
        {
            return std::stack<T>::c.end();
        }

        const_iterator begin() const
        {
            return std::stack<T>::c.begin();
        }

        const_iterator end() const
        {
            return std::stack<T>::c.end();
        }
};

#endif