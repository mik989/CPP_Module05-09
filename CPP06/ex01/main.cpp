#include "data.hpp"

int main()
{
	Data	data1("my data");

	// serializzo
	uintptr_t	test = Serializer::serialize(&data1);

	// deserializzo
	Data	*data2 = Serializer::deserialize(test);
	std::cout << std::endl << std::endl;

	std::cout << "ADRESSES COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 address: "<< &data1 << std::endl;
	std::cout << "Data2 address: "<< data2 << std::endl;
	std::cout << std::endl << std::endl;

	std::cout << "VALUES INSIDE DATA COMPARED:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << "Data1 value: " << data1.getValue() << std::endl;
	std::cout << "Data2 value: " << (*data2).getValue() << std::endl;
	std::cout << std::endl << std::endl;

	return (0);
}