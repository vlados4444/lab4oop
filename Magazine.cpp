#include "Magazine.h"
Magazine::Magazine() : PrintedPublication() {}
Magazine::Magazine(const char* t, const char* i, int p, const std::string& pub) : PrintedPublication(t, i, p, pub) {}
Magazine::Magazine(const Magazine& other) : PrintedPublication(other) {}
Magazine& Magazine::operator=(const Magazine& other) { if (this != &other) PrintedPublication::operator=(other); return *this; }
Magazine::~Magazine() {}
void Magazine::printInfo() const { std::cout << "[Magazine] \"" << title << "\", " << pages << " стр., " << publisher << ", ISBN: " << isbn << "\n"; }