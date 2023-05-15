#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>

class Span
{
    public:
    Span();
    Span(unsigned int n);
    ~Span();
    void addNumber(int nb);
    void addSomeNumbers(int min, int max);
    int shortestSpan();
    int longestSpan();

    private:
        unsigned int _n;
        std::vector<int> _container;
};

#endif