/**
 * @file Publication.cpp
 * @brief Реализация абстрактного класса Publication.
 */

#include "Publication.h"
#include <cstring>
#include <algorithm>

// Инициализация статических членов
int Publication::totalCount = 0;
int Publication::electronicCount = 0;
std::vector<Publication*> Publication::registry;

char* Publication::copyString(const char* src)
{
    if (!src) return nullptr;
    size_t len = std::strlen(src);
    char* dst = new char[len + 1];
    std::strcpy(dst, src);
    return dst;
}

Publication::Publication()
    : title(copyString("Unknown")), isbn(copyString("000-0-000-00000-0"))
{
    ++totalCount;
    registry.push_back(this);
}

Publication::Publication(const char* t, const char* i)
    : title(copyString(t ? t : "Unknown")), isbn(copyString(i ? i : "000-0-000-00000-0"))
{
    ++totalCount;
    registry.push_back(this);
}

Publication::Publication(const Publication& other)
    : title(copyString(other.title)), isbn(copyString(other.isbn))
{
    ++totalCount;
    registry.push_back(this);
}

Publication& Publication::operator=(const Publication& other)
{
    if (this == &other) return *this;
    delete[] title;
    delete[] isbn;
    title = copyString(other.title);
    isbn = copyString(other.isbn);
    return *this;
}

Publication::~Publication()
{
    --totalCount;
    // Удаляем себя из реестра
    registry.erase(std::remove(registry.begin(), registry.end(), this), registry.end());
    delete[] title;
    delete[] isbn;
}

void Publication::getShortInfo() const
{
    std::cout << "Publication: \"" << title << "\", ISBN: " << isbn << "\n";
}

Publication* Publication::findByISBN(const std::string& searchIsbn)
{
    for (auto* p : registry)
    {
        if (p && std::strcmp(p->getISBN(), searchIsbn.c_str()) == 0)
            return p;
    }
    return nullptr;
}

void showAllPublications(const Publication* const* arr, int n)
{
    std::cout << "--- All publications (" << n << ") ---\n";
    for (int i = 0; i < n; ++i)
        if (arr[i]) arr[i]->printInfo();
    std::cout << "--- End ---\n";
}