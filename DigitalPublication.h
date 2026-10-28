/**
 * @file DigitalPublication.h
 * @brief Заголовочный файл класса DigitalPublication.
 */

#ifndef DIGITALPUBLICATION_H
#define DIGITALPUBLICATION_H

#include "Publication.h"

/**
 * @brief Абстрактный класс для электронных изданий.
 * 
 * Добавляет размер файла и формат. Инкрементирует статический счётчик
 * electronicCount при создании.
 */
class DigitalPublication : virtual public Publication
{
protected:
    double fileSize;    ///< Размер файла в мегабайтах.
    std::string format; ///< Формат файла (PDF, EPUB, DJVU).

public:
    /// @brief Конструктор по умолчанию.
    DigitalPublication();
    
    /// @brief Параметризованный конструктор.
    DigitalPublication(const char* title, const char* isbn, double fileSize, const std::string& format);
    
    /// @brief Конструктор копирования.
    DigitalPublication(const DigitalPublication& other);
    
    /// @brief Оператор присваивания.
    DigitalPublication& operator=(const DigitalPublication& other);
    
    /// @brief Виртуальный деструктор.
    virtual ~DigitalPublication();

    /// @brief Переопределённый метод вывода краткой информации.
    void getShortInfo() const override;

    /// @return Размер файла в МБ.
    double getFileSize() const { return fileSize; }
    
    /// @return Формат файла.
    const std::string& getFormat() const { return format; }
};

#endif // DIGITALPUBLICATION_H