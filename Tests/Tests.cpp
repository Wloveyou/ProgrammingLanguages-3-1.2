#include "pch.h"
#include "CppUnitTest.h"
#include "../MatrixTask/Matrix.h"
#include "../Generators/RandomGenerator.h"

using namespace miit;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(Tests)
	{
	public:
		
		TEST_METHOD(Matrix_EqualOperator_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			Matrix matrix_2 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
		
			//act & assert
			Assert::IsTrue(matrix_1 == matrix_2);
		}

		TEST_METHOD(Matrix_IndexOperator_ValidData_Success)
		{
			// arrange
			Matrix matrix = Matrix({ {1, 2}, {3, 4} });
			int success = 3;

			// act & assert
			Assert::IsTrue(matrix[1][0] == success);
		}

		TEST_METHOD(Matrix_IndexOperator_IncorrectIndex_ExeptionExpected)
		{
			// arrange
			Matrix matrix = Matrix({ {1, 2}, {3, 4} });

			// act & assert
			Assert::ExpectException<std::out_of_range>([matrix]()
				{double x = matrix[3][4]; });
		}

		TEST_METHOD(Matrix_RowsCounts_ValidData_Success)
		{
			// arrange
			Matrix matrix = Matrix({ {1, 2}, {3, 4} });
			int answer = 2;

			// act
			int temp = matrix.rows_counts();

			// assert
			Assert::IsTrue(temp == answer);
		}

		TEST_METHOD(Matrix_ColumnsCounts_ValidData_Success)
		{
			// arrange
			Matrix matrix = Matrix({ {1, 2}, {3, 4} });
			int answer = 2;

			// act
			int temp = matrix.columns_counts();

			// assert
			Assert::IsTrue(temp == answer);
		}

		TEST_METHOD(Matrix_ToString_ValidData_Success)
		{
			// arrange
			Matrix matrix = Matrix({ {1, 2}, {3, 4}, {5, 6} });

			// act & assert
			Assert::IsTrue(matrix.to_string() == "1\t2\t\n3\t4\t\n5\t6\t\n");
		}

		TEST_METHOD(Matrix_Transpose_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			Matrix transposed = Matrix({ {1, 4, 7}, {2, 5, 8}, {3, 6, 9} });

			// act
			matrix_1.transpose();

			// assert
			Assert::IsTrue(matrix_1 == transposed);
		}

		TEST_METHOD(Matrix_AddRow_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			std::vector<int> row{ 1,1,1 };
			Matrix result = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {1, 1, 1} });

			// act
			matrix_1.add_row(row);

			// assert
			Assert::IsTrue(matrix_1 == result);
		}

		TEST_METHOD(Matrix_AddRowIndex_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			std::vector<int> row{ 1,1,1 };
			Matrix result = Matrix({ {1, 1, 1}, {1, 2, 3}, {4, 5, 6}, {7, 8, 9}});

			// act
			matrix_1.add_row(row, 0);

			// assert
			Assert::IsTrue(matrix_1 == result);
		}

		TEST_METHOD(Matrix_AddRowIndex_IncorrectIndex_ExeptionExpected)
		{
			// arrange & act & assert
			Assert::ExpectException<std::out_of_range>([]()
				{
					Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
					std::vector<int> row{ 1, 1, 1 };
					matrix_1.add_row(row, 10);
				});
		}

		TEST_METHOD(Matrix_AddColumn_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			std::vector<int> column{ 1,1,1 };
			Matrix result = Matrix({ {1, 2, 3, 1}, {4, 5, 6, 1}, {7, 8, 9, 1} });

			// act
			matrix_1.add_column(column);

			// assert
			Assert::IsTrue(matrix_1 == result);
		}

		TEST_METHOD(Matrix_AddColumnIndex_ValidData_Success)
		{
			// arrange
			Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
			std::vector<int> column{ 1,1,1 };
			Matrix result = Matrix({ {1, 1, 2, 3}, {1, 4, 5, 6}, {1, 7, 8, 9} });

			// act
			matrix_1.add_column(column, 0);

			// assert
			Assert::IsTrue(matrix_1 == result);
		}

		TEST_METHOD(Matrix_AddColumnIndex_IncorrectIndex_ExeptionExpected)
		{
			// arrange & act & assert
			Assert::ExpectException<std::out_of_range>([]()
				{
					Matrix matrix_1 = Matrix({ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} });
					std::vector<int> column{ 1, 1, 1 };
					matrix_1.add_column(column, 10);
				});
		}

		TEST_METHOD(MatrixGetMaxAbsElement_ValidData_Success)
		{
			// arrange
			Matrix matrix = Matrix({{22, 1, -30}, {7, 23, 5}, {-3, 4, -12}});
			int success_value = -30;

			// act
			int temp = matrix.get_abs_max_element();

			// assert
			Assert::IsTrue(temp == success_value);
		}

		TEST_METHOD(MatrixIsElementInRow_ValidData_Success)
		{	
			// arrange
			Matrix matrix = Matrix({ {22, 1, -30}, {7, 23, 5}, {-3, 4, -12} });
			
			// act
			int temp_1 = matrix.is_element_in_row(23, 1);
			int temp_2 = matrix.is_element_in_row(23, 0);

			// assert
			Assert::IsTrue(temp_1 == true && temp_2 == false);
		}

		TEST_METHOD(Matrix_CtorGenerator_IncorrectSize_ExeptionExpected)
		{
			// arrange & act & assert
			Assert::ExpectException<std::out_of_range>([]()
				{
					Generator* gen = new RandomGenerator(10, 100);
					Matrix matrix_1 = Matrix(-3, -2, gen);
				});
		}

		TEST_METHOD(Matrix_CtorMatrix_IncorrectMatrixData_ExeptionExpected)
		{
			// arrange & act & assert
			Assert::ExpectException<std::out_of_range>([]()
				{
					Matrix matrix_1 = Matrix({{ 1, 2, 3 }, { 1, 2, 3, 4 }, { 1, 2, 3 }});
				});
		}
	};
}
