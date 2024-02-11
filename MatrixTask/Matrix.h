#pragma once
#include "../Generators/Generator.h"
#include <iostream>
#include <vector>

namespace miit
{
	
	class Matrix
	{
	public:
		
		Matrix(size_t user_rows, size_t user_columns, Generator* generator);

		Matrix(size_t user_rows, size_t user_columns, std::initializer_list<int> data);

		Matrix();

		friend std::ostream& operator<<(std::ostream& os, Matrix& matrix) noexcept;

		friend bool operator==(Matrix& lha, Matrix& rha) noexcept;

		std::vector<int>& operator[](size_t index);

		const std::vector<int>& operator[](size_t index) const;

		size_t rows_counts() const;

		size_t columns_counts() const;

		std::string to_string() const noexcept;

		int get_abs_max_element() const;

		void add_row(std::vector<int> user_data, size_t index);

		void add_row(std::vector<int> user_data);

		void add_column(std::vector<int> user_data, size_t index);

		void add_column(std::vector<int> user_data);

		bool is_element_in_row(int value, size_t row_id);

		void transpose();

	private:
		std::vector<std::vector<int>> data;
	};


};