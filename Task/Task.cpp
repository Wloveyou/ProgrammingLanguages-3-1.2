#include "Task.h"

Task::Task(Matrix matrix)
	:matrix{ matrix }
{
}

Matrix Task::task_1()
{
	Matrix result{ this->matrix };
	int max = this->matrix.get_abs_max_element();
	for (size_t i = 0; i < result.rows_counts(); i++)
	{
		for (size_t j = 0; j < result.columns_counts(); j++)
		{
			if (result[i][j] == max)
			{
				result[i][j] = 0;
			}
		}
	}
	return result;
}

Matrix Task::task_2()
{
	Matrix result{};
	std::vector<int> zero_row;
	for (size_t i = 0; i < matrix.rows_counts(); i++)
	{
		zero_row.push_back(0);
	}
	int max = this->matrix.get_abs_max_element();
	for (size_t i = 0; i < matrix.rows_counts(); i++)
	{
		result.add_row(matrix[i]);
		if (this->matrix.is_element_in_row(max, i))
		{
			result.add_row(zero_row);
		}
	}
	return result;
}