/**
 * @file ship.h
 * @brief Определение класса Ship для представления информации о корабле.
 */

#ifndef SHIP_H
#define SHIP_H

#include <string>

/**
 * @brief Перечисление типов кораблей.
 */
enum ShipType
{
    TANKER,       ///< Танкер
    BULK_CARRIER, ///< Балкер (грузовой)
    PASSENGER     ///< Пассажирский
};

/**
 * @brief Класс Ship представляет корабль с его характеристиками.
 */
class Ship
{
private:
    std::string name;      ///< Название корабля
    int year;              ///< Год постройки
    std::string country;   ///< Страна происхождения
    ShipType ship_type;    ///< Тип корабля
    std::string captain;   ///< Имя капитана

public:
    /**
     * @brief Конструктор по умолчанию.
     */
    Ship();

    /**
     * @brief Конструктор с параметрами.
     * @param name Название корабля.
     * @param year Год постройки.
     * @param country Страна происхождения.
     * @param ship_type Тип корабля.
     * @param captain Имя капитана.
     */
    Ship(const std::string &name, int year, const std::string &country, ShipType ship_type, const std::string &captain);

    /// @name Геттеры
    /// Методы для получения значений полей.
    /// @{
    
    /**
     * @brief Получить название корабля.
     * @return Название корабля.
     */
    std::string getName() const;

    /**
     * @brief Получить год постройки.
     * @return Год постройки.
     */
    int getYear() const;

    /**
     * @brief Получить страну происхождения.
     * @return Страна происхождения.
     */
    std::string getCountry() const;

    /**
     * @brief Получить тип корабля.
     * @return Тип корабля.
     */
    ShipType getShipType() const;

    /**
     * @brief Получить имя капитана.
     * @return Имя капитана.
     */
    std::string getCaptain() const;

    /// @}

    /// @name Сеттеры
    /// Методы для установки значений полей.
    /// @{

    /**
     * @brief Установить название корабля.
     * @param name Новое название корабля.
     */
    void setName(const std::string &name);

    /**
     * @brief Установить год постройки.
     * @param year Новый год постройки.
     */
    void setYear(int year);

    /**
     * @brief Установить страну происхождения.
     * @param country Новая страна происхождения.
     */
    void setCountry(const std::string &country);

    /**
     * @brief Установить тип корабля.
     * @param ship_type Новый тип корабля.
     */
    void setShipType(ShipType ship_type);

    /**
     * @brief Установить имя капитана.
     * @param captain Новое имя капитана.
     */
    void setCaptain(const std::string &captain);

    /// @}

    /// @name Операторы сравнения
    /// Перегруженные операторы для сравнения кораблей.
    /// @{
    
    /**
     * @brief Оператор равенства.
     * @param ship Другой объект Ship.
     * @return true, если корабли равны, иначе false.
     */
    bool operator==(const Ship &ship) const;

    /**
     * @brief Оператор "меньше".
     * @param ship Другой объект Ship.
     * @return true, если данный корабль меньше переданного.
     */
    bool operator<(const Ship &ship) const;

    /**
     * @brief Оператор "больше".
     * @param ship Другой объект Ship.
     * @return true, если данный корабль больше переданного.
     */
    bool operator>(const Ship &ship) const;

    /**
     * @brief Оператор "меньше или равно".
     * @param ship Другой объект Ship.
     * @return true, если данный корабль меньше или равен переданному.
     */
    bool operator<=(const Ship &ship) const;

    /**
     * @brief Оператор "больше или равно".
     * @param ship Другой объект Ship.
     * @return true, если данный корабль больше или равен переданному.
     */
    bool operator>=(const Ship &ship) const;

    /// @}
};

#endif // SHIP_H