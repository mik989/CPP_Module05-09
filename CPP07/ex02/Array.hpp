#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array
{
public:
		Array<T>()
		{
			_n = 0;
			_bho = NULL;
		}
		Array<T>(unsigned int n)
		{
			_n = n;
			_bho = new T[n];
		}
		~Array<T>()
		{
			if (_bho != NULL)
				delete [] this->_bho;
			return;
		}
		//--------Copy constructor---------//
		Array<T>(Array<T> const & other)
		{
			(*this = other);
		}
		T*copy(Array const &src)
		{
			T* bho = new T[_n]();
			for(unsigned int i = 0; i < _n; i++)
				bho[i] = src._bho[i];
			return bho;
		}
		//--------Operator = override---------//
		Array<T> & operator= ( const Array<T> & other)
		{
			if(this == &other)
				return (*this);
			_n = other._n;
			_bho = copy(other);
			return (*this);
		}
		T & operator[](unsigned int n)
		{
			if (n < _n && n >= 0)
				return (_bho[n]);
			else
				throw(std::exception());
		}
		unsigned int size()
		{
			return(this->_n);
		}
private:
		T *_bho;
		unsigned int _n;
};

#endif