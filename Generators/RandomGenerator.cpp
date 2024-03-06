#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int min, int max)
{
	this->generator = std::mt19937(std::random_device{}());
	this->distribution = std::uniform_int_distribution<int>(min, max);
}

int RandomGenerator::generate()
{
	return this->distribution(this->generator);
}