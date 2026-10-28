#include "Book.h"
Book::Book() : PrintedPublication() {}
Book::Book(const char* t, const char* i, int p, const std::string& pub) : PrintedPublication(t, i, p, pub) {}
Book::Book(const Book& other) : PrintedPublication(other) {}
Book& Book::operator=(const Book& other) { if (this != &other) PrintedPublication::operator=(other); return *this; }
Book::~Book() {}
void Book::printInfo() const { std::cout << "[Book] \"" << title << "\", " << pages << " стр., " << publisher << ", ISBN: " << isbn << "\n"; }