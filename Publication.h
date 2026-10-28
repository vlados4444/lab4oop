/**
 * @file Publication.h
 * @brief Заголовочный файл абстрактного базового класса Publication.
 */

#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Абстрактный базовый класс для всех видов изданий.
 * 
 * Обеспечивает хранение названия и ISBN в виде динамических C-строк (char*).
 * Это требует реализации конструктора копирования и оператора присваивания
 * с глубоким копированием для предотвращения утечек и двойного удаления.
 * 
 * @section static_state Статическое состояние
 * - totalCount: общее количество созданных изданий.
 * - electronicCount: количество созданных электронных изданий.
 * - registry: глобальный вектор указателей на все издания для поиска.
 */
class Publication
{
protected:
    char* title;   ///< Название издания (глубокое копирование).
    char* isbn;    ///< ISBN издания (глубокое копирование).

    static int totalCount;      ///< Общий счётчик изданий.
    static int electronicCount; ///< Счётчик электронных изданий.
    
    /// @brief Статический реестр всех изданий для метода findByISBN.
    static std::vector<Publication*> registry;

    /**
     * @brief Вспомогательный метод для выделения памяти и копирования C-строки.
     * @param src Исходная строка.
     * @return Указатель на новую строку в динамической памяти.
     */
    static char* copyString(const char* src);

public:
    /// @brief Конструктор по умолчанию. Создаёт "Unknown".
    Publication();

    /**
     * @brief Параметризованный конструктор.
     * @param title Название.
     * @param isbn ISBN.
     */
    Publication(const char* title, const char* isbn);

    /// @brief Конструктор копирования (глубокое копирование).
    Publication(const Publication& other);

    /// @brief Оператор присваивания (глубокое копирование).
    Publication& operator=(const Publication& other);

    /// @brief Виртуальный деструктор для корректного удаления наследников.
    virtual ~Publication();

    /// @brief Чисто виртуальный метод: получить название.
    virtual const char* getTitle() const = 0;

    /// @brief Чисто виртуальный метод: получить ISBN.
    virtual const char* getISBN() const = 0;

    /// @brief Чисто виртуальный метод: вывод полной информации.
    virtual void printInfo() const = 0;

    /// @brief Виртуальный метод с реализацией по умолчанию.
    virtual void getShortInfo() const;

    /// @return Общее количество изданий.
    static int getTotalCount() { return totalCount; }

    /// @return Количество электронных изданий.
    static int getElectronicCount() { return electronicCount; }

    /**
     * @brief Статический метод поиска издания по ISBN.
     * @param searchIsbn Искомый ISBN.
     * @return Указатель на издание или nullptr, если не найдено.
     */
    static Publication* findByISBN(const std::string& searchIsbn);

    /// @brief Дружественная функция для вывода массива изданий.
    friend void showAllPublications(const Publication* const* arr, int n);
};

#endif // PUBLICATION_H