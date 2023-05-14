#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>


template <typename T>
class Array
{
    public:
        Array()
        {
            T *array = new T;
        }        
        Array(unsigned int n) : size_(n)
        {
            T *array = new T[n];
        }
        Array(Array const &copy)
        {
           
        }
        ~Array();
        Array &operator=(Array const &rhs)
        {
           
        }
        T& operator[](unsigned int index) 
        {
            if (index >= size_) 
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }    
        const T& operator[](unsigned int index) const 
        {
            if (index >= size_) 
            {
                throw std::out_of_range("Index out of range");
            }
            return data_[index];
        }
    
private:
    T* data_;
    unsigned int size_;
};

#endif