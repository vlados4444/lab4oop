/**
 * @file HybridBook.h
 * @brief Класс гибридного издания (множественное наследование).
 */

#ifndef HYBRIDBOOK_H
#define HYBRIDBOOK_H

#include "Book.h"
#include "DigitalPublication.h"

/**
 * @brief Гибридная книга: имеет как печатную, так и электронную версию.
 * 
 * Наследуется от Book и DigitalPublication. Благодаря виртуальному
 * наследованию в базовых классах, Publication существует в единственном
 * экземпляре.
 */
class HybridBook : public Book, public DigitalPublication
{
public:
    HybridBook();
    HybridBook(const char* title, const char* isbn,
               int pages, const std::string& publisher,
               double fileSize, const std::string& format);
    HybridBook(const HybridBook& other);
    HybridBook& operator=(const HybridBook& other);
    virtual ~HybridBook();

    // Явное указание на поля Publication убирает неоднозначность
    const char* getTitle() const override { return Publication::title; }
    const char* getISBN() const override { return Publication::isbn; }
    
    // Явно переопределяем методы, чтобы убрать неоднозначность
    void getShortInfo() const override;
    void printInfo() const override;
};

#endif // HYBRIDBOOK_H