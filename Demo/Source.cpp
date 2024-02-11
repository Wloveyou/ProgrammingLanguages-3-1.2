#include <iostream>
#include "../MatrixTask/Matrix.h"
#include "../Generators/RandomGenerator.h"

int main() 
{
	Generator* gen = new RandomGenerator(10, 29);
	auto a = miit::Matrix(5,5, gen);
	std::cout << a;
	return 0;
}