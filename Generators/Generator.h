#pragma once

/**
* @brief Базовый класс генератора
*/
class Generator
{
public:
	/**
	* @brief Чисто виртуальный деструктор
	*/
	virtual ~Generator() = 0 {};

	/**
	* @brief Чисто виртуальный метод для генерации чисел в классах наследниках
	*/
	virtual int generate() = 0;
};