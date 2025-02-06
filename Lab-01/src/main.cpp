/**
 * @file main.cpp
 * @brief Главный файл проекта. Запускает сортировки.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>
#include <algorithm>

#include "sorts.h"
#include "ship.h"

ShipType stringToShipType(const std::string &typeStr)
{
    if (typeStr == "Tanker")
        return TANKER;
    if (typeStr == "BulkCarrier")
        return BULK_CARRIER;
    if (typeStr == "Passenger")
        return PASSENGER;
    throw std::invalid_argument("Unknown ship type: " + typeStr);
}

std::vector<Ship> read_csv(const std::string &filename)
{
    std::vector<Ship> ships;
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Ошибка открытия файла!\n";
        return ships;
    }

    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        std::stringstream ss(line);
        std::string name, country, typeStr, captain;
        int year;

        getline(ss, name, ',');
        ss >> year;
        ss.ignore();
        getline(ss, country, ',');
        getline(ss, typeStr, ',');
        getline(ss, captain, ',');

        try
        {
            ShipType type = stringToShipType(typeStr);
            ships.emplace_back(name, year, country, type, captain);
        }
        catch (const std::exception &e)
        {
            std::cerr << "Ошибка парсинга строки: " << e.what() << std::endl;
        }
    }
    file.close();
    return ships;
}

void write_csv(const std::string &filename, const std::vector<Ship> &ships)
{
    std::ofstream file("data/sorted/" + filename);
    file << "Name,Year,Country,Type,Captain\n";
    for (const auto &ship : ships)
    {
        file << ship.getName() << ","
             << ship.getYear() << ","
             << ship.getCountry() << ","
             << (ship.getShipType() == TANKER ? "TANKER" : ship.getShipType() == BULK_CARRIER ? "BULK_CARRIER"
                                                                                              : "PASSENGER")
             << "," << ship.getCaptain() << "\n";
    }
    file.close();
}

template <typename Func>
double measure_sort(Func sort_func, std::vector<Ship> &ships)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(ships);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double>(end - start).count();
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <csv_filename> <algorithm>\n";
        return 1;
    }

    std::string filename = argv[1];
    std::string algorithm = argv[2];

    std::vector<Ship> ships = read_csv(filename);
    if (ships.empty())
    {
        std::cerr << "Файл пуст или не удалось загрузить данные.\n";
        return 1;
    }

    double elapsed_time = 0.0;

    if (algorithm == "insertion")
    {
        elapsed_time = measure_sort(insertionSort, ships);
    }
    else if (algorithm == "heap")
    {
        elapsed_time = measure_sort(heapSort, ships);
    }
    else if (algorithm == "merge")
    {
        elapsed_time = measure_sort([&](std::vector<Ship> &s)
                                    { mergeSort(s, 0, s.size() - 1); }, ships);
    }
    else
    {
        std::cerr << "Unknown algorithm: " << algorithm << "\n";
        return 1;
    }

    write_csv("sorted_ships_by_" + std::to_string(ships.size()) + "_" + algorithm + ".csv", ships);

    std::cout << "Sorting algorithm: " << algorithm << "\n";
    std::cout << "Sorting time: " << elapsed_time << " seconds\n";

    return 0;
}