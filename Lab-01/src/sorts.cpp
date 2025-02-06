/**
 * @file sorts.cpp
 * @brief Реализация различных алгоритмов сортировки для объектов класса Ship.
 */

#include "sorts.h"
#include <algorithm>

/**
 * @brief Сортировка вставками.
 * 
 * Алгоритм сортировки вставками последовательно берет каждый элемент
 * и вставляет его в отсортированную часть массива.
 * 
 * @param ships Вектор объектов Ship для сортировки.
 */
void insertionSort(std::vector<Ship>& ships) {
    for (size_t i = 1; i < ships.size(); ++i) {
        Ship key = ships[i];
        int j = i - 1;

        while (j >= 0 && ships[j] > key) {
            ships[j + 1] = ships[j];
            --j;
        }
        ships[j + 1] = key;
    }
}

// --- Пирамидальная сортировка ---

/**
 * @brief Функция heapify для корректировки кучи.
 * 
 * Вспомогательная функция, которая поддерживает свойство кучи.
 * 
 * @param ships Вектор объектов Ship.
 * @param n Размер кучи.
 * @param i Индекс узла, который нужно обработать.
 */
void heapify(std::vector<Ship>& ships, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && ships[left] > ships[largest])
        largest = left;

    if (right < n && ships[right] > ships[largest])
        largest = right;

    if (largest != i) {
        std::swap(ships[i], ships[largest]);
        heapify(ships, n, largest);
    }
}

/**
 * @brief Пирамидальная (кучевая) сортировка.
 * 
 * Алгоритм строит бинарную кучу и последовательно извлекает максимальные элементы.
 * 
 * @param ships Вектор объектов Ship для сортировки.
 */
void heapSort(std::vector<Ship>& ships) {
    int n = ships.size();

    // Построение max-heap
    for (int i = n / 2 - 1; i >= 0; --i)
        heapify(ships, n, i);

    // Извлечение элементов из кучи
    for (int i = n - 1; i > 0; --i) {
        std::swap(ships[0], ships[i]);
        heapify(ships, i, 0);
    }
}

// --- Сортировка слиянием ---

/**
 * @brief Функция объединения (merge) двух подмассивов.
 * 
 * @param ships Вектор объектов Ship.
 * @param left Начальный индекс левой части.
 * @param mid Средний индекс (разделение массивов).
 * @param right Конечный индекс правой части.
 */
void merge(std::vector<Ship>& ships, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Ship> L(n1), R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = ships[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = ships[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] < R[j]) {
            ships[k] = L[i];
            ++i;
        } else {
            ships[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        ships[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        ships[k] = R[j];
        ++j;
        ++k;
    }
}

/**
 * @brief Рекурсивная сортировка слиянием.
 * 
 * Разделяет массив на подмассивы, сортирует их и объединяет обратно.
 * 
 * @param ships Вектор объектов Ship для сортировки.
 * @param left Левый индекс диапазона сортировки.
 * @param right Правый индекс диапазона сортировки.
 */
void mergeSort(std::vector<Ship>& ships, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(ships, left, mid);
        mergeSort(ships, mid + 1, right);

        merge(ships, left, mid, right);
    }
}