#pragma once 
#include "../MatrixTask/Matrix.h"

using namespace miit;

/**
* @brief Базовый класс задания от которого можно отнаследовать свое задание с 2 подзаданиями
*/
struct TaskBase
{
public:
	/**
	* @brief Чисто виртуальный деструктор
	*/
	virtual ~TaskBase() = 0 {};

	/**
	* @brief Чисто виртуальный метод для выполениея первого подзадания
	*/
	virtual Matrix task_1() = 0;

	/**
	* @brief Чисто виртуальный метод для выполениея второго подзадания
	*/
	virtual Matrix task_2() = 0;
};