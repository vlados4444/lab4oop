#include "EBook.h"
EBook::EBook() : DigitalPublication() {}
EBook::EBook(const char* t, const char* i, double fs, const std::string& f) : DigitalPublication(t, i, fs, f) {}
EBook::EBook(const EBook& other) : DigitalPublication(other) {}
EBook& EBook::operator=(const EBook& other) { if (this != &other) DigitalPublication::operator=(other); return *this; }
EBook::~EBook() {}
void EBook::printInfo() const { std::cout << "[EBook] \"" << title << "\", " << fileSize << " МБ, " << format << ", ISBN: " << isbn << "\n"; }