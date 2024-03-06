#include "IStreamGenerator.h"

IStreamGenerator::IStreamGenerator(std::istream& input)
	:in{ input }
{
}

int IStreamGenerator::generate()
{
	int value = 0;
	this->in >> value;
	return value;
}