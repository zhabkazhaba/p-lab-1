#pragma once
#include <string>
#include <tuple>

/**
 * @brief Структура с данными о жильце района
 * 
 * Используется для последующих сортировок
 */
struct Resident {
    std::string fio;        ///< ФИО жильца 
    std::string street;     ///< Название улицы 
    int house;              ///< Номер дома 
    int apartment;          ///< Номер квартиры 
    int birth_year;         ///< Год рождения 

    /**
     * @brief Оператор "меньше"
     * 
     * Сравнивает жильцов лексикографически
     */
    bool operator<(const Resident& other) const {
        return std::tie(street, house, apartment, fio, birth_year) < 
               std::tie(other.street, other.house, other.apartment, other.fio, other.birth_year);
    }

    /**
     * @brief Оператор "больше"
     */
    bool operator>(const Resident& other) const {
        return std::tie(street, house, apartment, fio, birth_year) > 
               std::tie(other.street, other.house, other.apartment, other.fio, other.birth_year);
    }

    /**
     * @brief Оператор "меньше или равно"
     */
    bool operator<=(const Resident& other) const {
        return !(*this > other);
    }

    /**
     * @brief Оператор "больше или равно"
     */
    bool operator>=(const Resident& other) const {
        return !(*this < other);
    }
};