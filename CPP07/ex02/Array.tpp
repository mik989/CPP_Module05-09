#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
    T *array = new T;
}

template <typename T>
Array<T>::Array(unsigned int n) : size_(n)
{
    T array[n] = new T;
}

template <typename T>
Array<T>::Array(Array const &copy) 
{
    this->array = copy.array;
}

template <typename T>
Array<T>::~Array()
{
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &rhs)
{
    if (this != &rhs)
    {
        this->array = rhs.array;
    }
    return *this;
}


