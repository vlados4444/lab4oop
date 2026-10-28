/**
 * @file HybridBook.cpp
 * @brief Реализация класса HybridBook.
 */

#include "HybridBook.h"

// При виртуальном наследовании HybridBook (самый производный класс)
// обязан явно инициализировать Publication.
HybridBook::HybridBook()
    : Publication(), Book(), DigitalPublication() 
{}

HybridBook::HybridBook(const char* t, const char* i,
                       int p, const std::string& pub,
                       double fs, const std::string& f)
    : Publication(t, i), // <-- явная инициализация виртуальной базы
      Book(t, i, p, pub),
      DigitalPublication(t, i, fs, f) 
{}

HybridBook::HybridBook(const HybridBook& other)
    : Publication(other), // <-- явная инициализация виртуальной базы
      Book(other),
      DigitalPublication(other) 
{}

HybridBook& HybridBook::operator=(const HybridBook& other)
{
    if (this == &other) return *this;
    
    // Копируем базу один раз (т.к. она виртуальная)
    Publication::operator=(other);
    Book::operator=(other);
    DigitalPublication::operator=(other);
    
    return *this;
}

HybridBook::~HybridBook() {}

void HybridBook::getShortInfo() const
{
    std::cout << "Hybrid: \"" << getTitle() << "\", "
              << getPages() << " стр. / " << getFileSize() << " МБ, "
              << "ISBN: " << getISBN() << "\n";
}

void HybridBook::printInfo() const
{
    std::cout << "[HybridBook] \"" << getTitle() << "\", "
              << getPages() << " стр. (" << getPublisher() << "), "
              << getFileSize() << " МБ (" << getFormat() << "), "
              << "ISBN: " << getISBN() << "\n";
}