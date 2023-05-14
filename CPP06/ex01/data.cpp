#include "data.hpp"

Data::Data()
{
}
Data::~Data()
{

}
Data::Data(std::string value) : _value(value)
{
}
Data::Data(Data const & ref)
{
    *this = ref;
}
Data & Data::operator=(Data const & ref)
{
    return(*this);
}
std::string Data::getValue( void ) const
{
    return (this->_value);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return	(reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return	(reinterpret_cast<Data *>(raw));
}