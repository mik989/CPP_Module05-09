#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <iomanip>
#include <iostream>
#include <stdint.h>

class Data
{
	public:
		Data();
		~Data();
		Data(std::string value);
		Data(Data const & ref);
		Data & operator=(Data const & ref);

		std::string getValue( void ) const;
	private:
		std::string _value;
};

class Serializer
{
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif