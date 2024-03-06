#pragma once
#include "TaskBase.h"
#include "../MatrixTask/Matrix.h"



/**
* @brief Класс задание, наследник базового задания, с 2 подзаданиями
*/
struct Task : public TaskBase
{
private:
	Matrix matrix;

public:
	/**
	* @brief Инициализирует объект типа "Task"
	* @param matrix Матрица для выполнения задания
	*/
	Task(Matrix matrix);

	/**
	* @brief Решение первой подзадачи
	* @return Матрица выполненного задания
	*/
	Matrix task_1() override;

	/**
	* @brief Решение второй подзадачи 
	* @return Матрица выполненного задания
	*/
	Matrix task_2() override;
};