#pragma once
#include "Generator.h"
#include <iostream>


class IStreamGenerator : public Generator
{
private:
	std::istream& in;

public:
	
	IStreamGenerator(std::istream& input = std::cin);

	int generate() override;
};