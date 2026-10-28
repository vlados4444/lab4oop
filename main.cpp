/**
 * @file main.cpp
 * @brief Тестирование иерархии Publication.
 */

#include "Publication.h"
#include "Book.h"
#include "Magazine.h"
#include "EBook.h"
#include "HybridBook.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

std::vector<Publication*> loadFromFile(const std::string& filename)
{
    std::vector<Publication*> result;
    std::ifstream file(filename);
    std::string line;

    while (std::getline(file, line))
    {
        if (line.empty()) continue;
        std::istringstream ss(line);
        std::string type, title, isbn;
        std::getline(ss, type, ';');
        std::getline(ss, title, ';');
        std::getline(ss, isbn, ';');

        if (type == "Book")
        {
            std::string p, pub;
            std::getline(ss, p, ';'); std::getline(ss, pub, ';');
            result.push_back(new Book(title.c_str(), isbn.c_str(), std::stoi(p), pub));
        }
        else if (type == "Magazine")
        {
            std::string p, pub;
            std::getline(ss, p, ';'); std::getline(ss, pub, ';');
            result.push_back(new Magazine(title.c_str(), isbn.c_str(), std::stoi(p), pub));
        }
        else if (type == "EBook")
        {
            std::string fs, f;
            std::getline(ss, fs, ';'); std::getline(ss, f, ';');
            result.push_back(new EBook(title.c_str(), isbn.c_str(), std::stod(fs), f));
        }
        else if (type == "HybridBook")
        {
            std::string p, pub, fs, f;
            std::getline(ss, p, ';'); std::getline(ss, pub, ';');
            std::getline(ss, fs, ';'); std::getline(ss, f, ';');
            result.push_back(new HybridBook(title.c_str(), isbn.c_str(), std::stoi(p), pub, std::stod(fs), f));
        }
    }
    return result;
}

int main()
{
    std::cout << "=== 1. Чтение из файла ===\n";
    std::vector<Publication*> all = loadFromFile("publications.txt");
    std::cout << "Загружено: " << all.size() << " изданий\n";
    std::cout << "Всего изданий: " << Publication::getTotalCount() << "\n";
    std::cout << "Электронных: " << Publication::getElectronicCount() << "\n\n";

    std::cout << "=== 2. Полиморфный вызов ===\n";
    for (auto* p : all) p->printInfo();

    std::cout << "\n=== 3. Поиск по ISBN ===\n";
    Publication* found = Publication::findByISBN("978-5-04-098765-4");
    if (found) { std::cout << "Найдено: "; found->printInfo(); }
    else std::cout << "Не найдено\n";

    std::cout << "\n=== 4. Копирование HybridBook ===\n";
    HybridBook original("Test Hybrid", "111-222", 100, "TestPub", 5.0, "PDF");
    HybridBook copy = original;

    std::cout << "Original: "; original.printInfo();
    std::cout << "Copy:     "; copy.printInfo();
    std::cout << "Независимость памяти: original title = " << static_cast<const void*>(original.getTitle())
              << ", copy title = " << static_cast<const void*>(copy.getTitle()) << "\n";

    std::cout << "\n=== 5. Дружественная функция ===\n";
    const Publication* arr[] = { all[0], all[1], all[2] };
    showAllPublications(arr, 3);

    std::cout << "\n=== 6. Освобождение памяти ===\n";
    for (auto* p : all) delete p;
    std::cout << "Осталось изданий: " << Publication::getTotalCount() << "\n";

    return 0;
}