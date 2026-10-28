/**
 * @file EBook.h
 * @brief Конкретный класс Электронная книга.
 */

#ifndef EBOOK_H
#define EBOOK_H
#include "DigitalPublication.h"

/// @brief Электронная книга — конкретное цифровое издание.
class EBook : public DigitalPublication
{
public:
    EBook();
    EBook(const char* title, const char* isbn, double fileSize, const std::string& format);
    EBook(const EBook& other);
    EBook& operator=(const EBook& other);
    virtual ~EBook();

    const char* getTitle() const override { return title; }
    const char* getISBN() const override { return isbn; }
    void printInfo() const override;
};
#endif