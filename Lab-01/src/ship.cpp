/**
 * @file ship.cpp
 * @brief Реализация класса Ship, представляющего корабль.
 */

#include "ship.h"

/**
 * @brief Конструктор по умолчанию.
 * 
 * Инициализирует объект Ship с пустыми значениями.
 */
Ship::Ship() : name(""), year(0), country(""), ship_type(TANKER), captain("") {}

/**
 * @brief Конструктор с параметрами.
 * 
 * @param name Название корабля.
 * @param year Год постройки.
 * @param country Страна производства.
 * @param ship_type Тип корабля (Tank, Bulk Carrier, Passenger).
 * @param captain Имя капитана.
 */
Ship::Ship(const std::string& name, int year, const std::string& country, ShipType ship_type, const std::string& captain)
    : name(name), year(year), country(country), ship_type(ship_type), captain(captain) {}

// Геттеры

/**
 * @brief Получает название корабля.
 * @return Название корабля.
 */
std::string Ship::getName() const { return name; }

/**
 * @brief Получает год постройки корабля.
 * @return Год постройки.
 */
int Ship::getYear() const { return year; }

/**
 * @brief Получает страну производства корабля.
 * @return Название страны.
 */
std::string Ship::getCountry() const { return country; }

/**
 * @brief Получает тип корабля.
 * @return Тип корабля (Tank, Bulk Carrier, Passenger).
 */
ShipType Ship::getShipType() const { return ship_type; }

/**
 * @brief Получает имя капитана корабля.
 * @return Имя капитана.
 */
std::string Ship::getCaptain() const { return captain; }

// Сеттеры

/**
 * @brief Устанавливает название корабля.
 * @param name Новое название корабля.
 */
void Ship::setName(const std::string& name) { this->name = name; }

/**
 * @brief Устанавливает год постройки корабля.
 * @param year Новый год постройки.
 */
void Ship::setYear(int year) { this->year = year; }

/**
 * @brief Устанавливает страну производства корабля.
 * @param country Новая страна производства.
 */
void Ship::setCountry(const std::string& country) { this->country = country; }

/**
 * @brief Устанавливает тип корабля.
 * @param ship_type Новый тип корабля.
 */
void Ship::setShipType(ShipType ship_type) { this->ship_type = ship_type; }

/**
 * @brief Устанавливает имя капитана корабля.
 * @param captain Новое имя капитана.
 */
void Ship::setCaptain(const std::string& captain) { this->captain = captain; }

// Операторы сравнения

/**
 * @brief Оператор сравнения (равенство).
 * 
 * @param ship Другой объект Ship.
 * @return true, если все поля совпадают.
 */
bool Ship::operator==(const Ship& ship) const {
    return name == ship.name && year == ship.year && country == ship.country &&
           ship_type == ship.ship_type && captain == ship.captain;
}

/**
 * @brief Оператор меньше.
 * 
 * @param ship Другой объект Ship.
 * @return true, если текущий корабль старше (по году постройки).
 */
bool Ship::operator<(const Ship& ship) const {
    return year < ship.year;
}

/**
 * @brief Оператор больше.
 * 
 * @param ship Другой объект Ship.
 * @return true, если текущий корабль новее (по году постройки).
 */
bool Ship::operator>(const Ship& ship) const {
    return year > ship.year;
}

/**
 * @brief Оператор меньше или равно.
 * 
 * @param ship Другой объект Ship.
 * @return true, если текущий корабль старше или того же года.
 */
bool Ship::operator<=(const Ship& ship) const {
    return !(*this > ship);
}

/**
 * @brief Оператор больше или равно.
 * 
 * @param ship Другой объект Ship.
 * @return true, если текущий корабль новее или того же года.
 */
bool Ship::operator>=(const Ship& ship) const {
    return !(*this < ship);
}