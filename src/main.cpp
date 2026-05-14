#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <fstream>
#include "resident.hpp"
#include "sort.hpp"
#include "util.hpp"

#ifdef _WIN32
#include <windows.h>
#endif

int main() {
    #ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    #endif

    std::string in_file = "../data/in_data.csv";
    std::string times_file = "../data/out_times.csv";

    std::cout << "Читаем данные из " << in_file << "\n";
    std::vector<Resident> original_data = read_csv(in_file);
    std::cout << "Успешно прочитано\n";

    if (original_data.empty()) {
        std::cerr << "Датасет пуст\n";
        return 1;
    }

    std::vector<int> sizes = {100, 500, 1000, 2500, 5000, 10000, 25000, 50000, 75000, 100000};

    std::ofstream t_file(times_file);
    if (!t_file.is_open()) {
        std::cerr << "Не удалось открыть файл для записи времени\n";
        return 1;
    }

    t_file << "Size;StdSort;HeapSort;InsertionSort;ShakerSort\n";

    for (long size : sizes) {
        std::cout << "Тестируется выборка размером " << size << "\n";
        if (size > original_data.size()) {
            continue;
        }

        std::vector<Resident> slice(original_data.begin(), original_data.begin() + size);

        auto data_std = slice;
        auto data_heap = slice;
        auto data_insertion = slice;
        auto data_shaker = slice;

        auto start = std::chrono::high_resolution_clock::now();
        std::sort(data_std.begin(), data_std.end());
        auto end = std::chrono::high_resolution_clock::now();
        long long time_std = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        heap_sort(data_heap);
        end = std::chrono::high_resolution_clock::now();
        long long time_heap = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        insertion_sort(data_insertion);
        end = std::chrono::high_resolution_clock::now();
        long long time_insertion = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        start = std::chrono::high_resolution_clock::now();
        shaker_sort(data_shaker);
        end = std::chrono::high_resolution_clock::now();
        long long time_shaker = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        t_file << size << ";" 
               << time_std << ";" 
               << time_heap << ";" 
               << time_insertion << ";" 
               << time_shaker << "\n";
    }

    std::string out_file = "../data/out_data.csv";
    std::vector<Resident> final_data = original_data;
    std::sort(final_data.begin(), final_data.end());

    std::cout << "Записываем данные в " << out_file << "\n";
    write_csv(out_file, final_data);
    std::cout << "Успешно записано\n";

    return 0;
}