/**
 * @file Magazine.h
 * @brief Конкретный класс Журнал.
 */

#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "PrintedPublication.h"

/// @brief Журнал — конкретное периодическое издание.
class Magazine : public PrintedPublication
{
public:
    Magazine();
    Magazine(const char* title, const char* isbn, int pages, const std::string& publisher);
    Magazine(const Magazine& other);
    Magazine& operator=(const Magazine& other);
    virtual ~Magazine();

    const char* getTitle() const override { return title; }
    const char* getISBN() const override { return isbn; }
    void printInfo() const override;
};
#endif