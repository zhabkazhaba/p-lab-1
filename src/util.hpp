#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "resident.hpp"

std::vector<Resident> read_csv(const std::string& filename) {
    std::vector<Resident> result;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл на чтение";
        return result;
    }

    std::string line;
    if (std::getline(file, line)) {}

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string fio, street, house_str, apt_str, year_str;

        std::getline(ss, fio, ';');
        std::getline(ss, street, ';');
        std::getline(ss, house_str, ';');
        std::getline(ss, apt_str, ';');
        std::getline(ss, year_str, ';');

        Resident r;
        r.fio = fio;
        r.street = street;
        r.house = std::stoi(house_str);
        r.apartment = std::stoi(apt_str);
        r.birth_year = std::stoi(year_str);
        result.push_back(r);
    }
    return result;
}

void write_csv(const std::string& filename, const std::vector<Resident>& data) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл на запись";
        return;
    }

    file << "fio;street;house;apartment;birth_year\n";
    
    for (const auto& r : data) {
        file << r.fio << ";" 
             << r.street << ";" 
             << r.house << ";" 
             << r.apartment << ";" 
             << r.birth_year << "\n";
    }
}