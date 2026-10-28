/**
 * @file Book.h
 * @brief Конкретный класс Книга.
 */

#ifndef BOOK_H
#define BOOK_H
#include "PrintedPublication.h"

/// @brief Книга — конкретное печатное издание.
class Book : public PrintedPublication
{
public:
    Book();
    Book(const char* title, const char* isbn, int pages, const std::string& publisher);
    Book(const Book& other);
    Book& operator=(const Book& other);
    virtual ~Book();

    const char* getTitle() const override { return title; }
    const char* getISBN() const override { return isbn; }
    void printInfo() const override;
};
#endif