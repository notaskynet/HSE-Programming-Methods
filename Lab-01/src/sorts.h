/**
 * @file sorts.h
 * @brief Определение алгоритмов сортировки для вектора объектов Ship.
 */

#ifndef SORTS_H
#define SORTS_H

#include <vector>
#include "ship.h"

/**
 * @brief Сортировка вставками (Insertion Sort).
 * 
 * @param ships Вектор кораблей, который необходимо отсортировать.
 * @details Алгоритм сортирует вектор объектов Ship по определённому критерию (например, по названию или году).
 */
void insertionSort(std::vector<Ship>& ships);

/**
 * @brief Пирамидальная сортировка (Heap Sort).
 * 
 * @param ships Вектор кораблей, который необходимо отсортировать.
 * @details Использует структуру кучи (heap) для сортировки элементов.
 */
void heapSort(std::vector<Ship>& ships);

/**
 * @brief Сортировка слиянием (Merge Sort).
 * 
 * @param ships Вектор кораблей, который необходимо отсортировать.
 * @param left Левая граница сортируемой части вектора.
 * @param right Правая граница сортируемой части вектора.
 * @details Рекурсивно делит массив на две части, сортирует их и объединяет обратно.
 */
void mergeSort(std::vector<Ship>& ships, int left, int right);

#endif // SORTS_H