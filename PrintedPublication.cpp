/**
 * @file PrintedPublication.cpp
 * @brief Реализация класса PrintedPublication.
 */

#include "PrintedPublication.h"

PrintedPublication::PrintedPublication()
    : Publication(), pages(1), publisher("Unknown") {}

PrintedPublication::PrintedPublication(const char* title, const char* isbn,
                                       int p, const std::string& pub)
    : Publication(title, isbn), pages(p), publisher(pub) {}

PrintedPublication::PrintedPublication(const PrintedPublication& other)
    : Publication(other), pages(other.pages), publisher(other.publisher) {}

PrintedPublication& PrintedPublication::operator=(const PrintedPublication& other)
{
    if (this == &other) return *this;
    Publication::operator=(other);
    pages = other.pages;
    publisher = other.publisher;
    return *this;
}

PrintedPublication::~PrintedPublication() {}

void PrintedPublication::getShortInfo() const
{
    std::cout << "Printed: \"" << title << "\", " << pages << " стр., "
              << publisher << ", ISBN: " << isbn << "\n";
}