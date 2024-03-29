#include "Matrix.h"
#include <random>
#include <sstream>


miit::Matrix::Matrix(int user_rows, int user_columns, Generator* generator)
	:data({})
{
	if (user_rows < 0 || user_columns < 0) 
	{
		throw std::out_of_range("Incorrect matrix size");
	}
	for (size_t i = 0; i < user_rows; i++)
	{
		std::vector<int> temp{};
		for (size_t j = 0; j < user_columns; j++)
		{
			temp.push_back(generator->generate());
		}
		this->data.push_back(temp);
	}
}

miit::Matrix::Matrix(std::initializer_list<std::initializer_list<int>> user_data)
	:data({})
{
	int constant_column_size = user_data.begin()->size();
	for (auto& row : user_data)
	{
		if (row.size() != constant_column_size) 
		{
			throw std::out_of_range("Not Matrix");
		}
		std::vector<int> temp{};
		for (auto& column : row)
		{
			temp.push_back(column);
		}
		this->data.push_back(temp);
	}
}

miit::Matrix::Matrix()
	:data(std::vector<std::vector<int>> {})
{
}

void miit::Matrix::add_row(std::vector<int> user_data, size_t index)
{
	if (index >= this->rows_counts())
	{
		throw std::out_of_range("incorrect index");
	}
	this->data.insert(data.begin() + index, user_data);
}

void miit::Matrix::add_row(std::vector<int> user_data)
{
	this->data.push_back(user_data);
}

void miit::Matrix::add_column(std::vector<int> user_data, size_t index)
{
	transpose();
	this->add_row(user_data, index);
	transpose();
}

void miit::Matrix::add_column(std::vector<int> user_data)
{
	transpose();
	this->add_row(user_data);
	transpose();
}

int miit::Matrix::get_abs_max_element() const
{
	int max = 0;
	for (size_t i = 0; i < this->rows_counts(); i++)
	{
		for (size_t j = 0; j < this->columns_counts(); j++)
		{
			if (std::abs(this->data[i][j]) >= std::abs(max))
			{
				max = this->data[i][j];
			}
		}
	}
	return max;
}

bool miit::Matrix::is_element_in_row(int value, size_t row_id)
{
	for (size_t i = 0; i < this->data[row_id].size(); i++)
	{
		if (this->data[row_id][i] == value)
		{
			return true;
		}
	}
	return false;
}

size_t miit::Matrix::rows_counts() const
{
	return this->data.size();
}

size_t miit::Matrix::columns_counts() const
{
	if (this->data.size() == 0)
	{
		return 0;
	}
	return this->data[0].size();
}

void miit::Matrix::transpose()
{
	std::vector<std::vector<int>> temp_data;
	for (size_t j = 0; j < this->data[0].size(); j++)
	{
		std::vector<int> temp{};
		for (size_t i = 0; i < this->data.size(); i++)
		{
			temp.push_back(this->data[i][j]);
		}
		temp_data.push_back(temp);
	}
	this->data = temp_data;

}

std::vector<int>& miit::Matrix::operator[](size_t index)
{
	if (index >= this->rows_counts()) 
	{
		throw std::out_of_range("Incorrect index");
	}
	return data[index];
}

const std::vector<int>& miit::Matrix::operator[](size_t index) const
{
	if (index >= this->rows_counts())
	{
		throw std::out_of_range("Incorrect index");
	}
	return data[index];
}

std::string miit::Matrix::to_string() const noexcept
{
	std::stringstream temp;
	for (size_t i = 0; i < this->rows_counts(); i++)
	{
		for (size_t j = 0; j < this->columns_counts(); j++)
		{
			temp << this->data[i][j] << "\t";
		}
		temp << "\n";
	}
	return temp.str();
}

std::ostream& miit::operator<<(std::ostream& os, Matrix& matrix) noexcept
{
	return os << matrix.to_string();
}

bool miit::operator==(Matrix& lha, Matrix& rha) noexcept
{
	return lha.to_string() == rha.to_string();
}