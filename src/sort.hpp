#pragma once
#include <vector>
#include <algorithm>
#include <utility> // для std::swap

/**
 * @brief Сортировка простыми вставками
 * 
 * @param arr Ссылка на вектор, который нужно отсортировать
 */
template <typename T>
void insertion_sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    int n = static_cast<int>(arr.size());
    
    for (int i = 1; i < n; ++i) {
        T key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/**
 * @brief Шейкер-сортировка
 * 
 * @param arr Ссылка на вектор, который нужно отсортировать.
 */
template <typename T>
void shaker_sort(std::vector<T>& arr) {
    if (arr.empty()) return;
    bool swapped = true;
    int start = 0;
    int end = static_cast<int>(arr.size()) - 1;

    while (swapped) {
        swapped = false;
        
        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
        swapped = false;
        --end;
        
        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        ++start;
    }
}

template <typename T>
void make_heap(std::vector<T>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        make_heap(arr, n, largest);
    }
}

/**
 * @brief Пирамидальная сортировка
 * 
 * @param arr Ссылка на вектор, который нужно отсортировать.
 */
template <typename T>
void heap_sort(std::vector<T>& arr) {
    int n = static_cast<int>(arr.size());

    for (int i = n / 2 - 1; i >= 0; i--)
        make_heap(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]); 
        make_heap(arr, i, 0);        
    }
}