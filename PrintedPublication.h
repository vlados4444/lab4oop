/**
 * @file PrintedPublication.h
 * @brief Заголовочный файл класса PrintedPublication.
 */

#ifndef PRINTEDPUBLICATION_H
#define PRINTEDPUBLICATION_H

#include "Publication.h"

/**
 * @brief Абстрактный класс для печатных изданий.
 * 
 * Добавляет специфичные для печати поля: количество страниц и издательство.
 * Реализует переопределение виртуального метода getShortInfo().
 */
class PrintedPublication : virtual public Publication
{
protected:
    int pages;             ///< Количество страниц.
    std::string publisher; ///< Название издательства.

public:
    /// @brief Конструктор по умолчанию.
    PrintedPublication();
    
    /// @brief Параметризованный конструктор.
    PrintedPublication(const char* title, const char* isbn, int pages, const std::string& publisher);
    
    /// @brief Конструктор копирования.
    PrintedPublication(const PrintedPublication& other);
    
    /// @brief Оператор присваивания.
    PrintedPublication& operator=(const PrintedPublication& other);
    
    /// @brief Виртуальный деструктор.
    virtual ~PrintedPublication();

    /// @brief Переопределённый метод вывода краткой информации.
    void getShortInfo() const override;

    /// @return Количество страниц.
    int getPages() const { return pages; }
    
    /// @return Название издательства.
    const std::string& getPublisher() const { return publisher; }
};

#endif // PRINTEDPUBLICATION_H