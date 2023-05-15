 #include "Span.hpp"
 
    Span::Span()
    {
    }
    Span::Span(unsigned int n) : _n(n)
    {
    }
    Span::~Span()
    {

    }
    void Span::addNumber(int nb)
    {
        if (this->_container.size() > this->_n)
            throw std::exception();
        this->_container.push_back(nb);
    }

    void Span::addSomeNumbers(int min, int max)
    {
        if(min >= max)
            throw std::exception();
        if((this->_container.size() + (max - min) > this->_n) || (this->_container.size() > this->_n))
            throw std::exception();
        for(int i = min; i < max; i++)
            this->_container.push_back(i);
    }
    int Span::shortestSpan()
    {
        if (_container.size() < 2) 
        {
            throw std::runtime_error("Cannot calculate shortest span with less than two elements.");
        }

        int val = 0;
        int res = INT_MAX;
        int i = 0;
        int j = 0;
        while (i < _container.size()) 
        {
            while (j < _container.size()) 
            {
                if (j == i)
                {
                    j++;
                    continue;
                }
                if(_container[j] >= _container[i])
                    val = _container[j] - _container[i];
                if(res > val && val != 0)
                        res = val;
                j++;
            }
            j = 0;
            i++;
        }
        return (res);
    }
    int Span::longestSpan()
    {
        std::vector<int>::const_iterator it_min = std::min_element(_container.cbegin(), _container.cend());
        std::vector<int>::const_iterator it_max = std::max_element(_container.cbegin(), _container.cend());

        return (*it_max - *it_min);
    }