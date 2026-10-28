/**
 * @file DigitalPublication.cpp
 * @brief Реализация класса DigitalPublication.
 */

#include "DigitalPublication.h"

DigitalPublication::DigitalPublication()
    : Publication(), fileSize(0.0), format("PDF")
{
    ++electronicCount;
}

DigitalPublication::DigitalPublication(const char* title, const char* isbn,
                                       double fs, const std::string& fmt)
    : Publication(title, isbn), fileSize(fs), format(fmt)
{
    ++electronicCount;
}

DigitalPublication::DigitalPublication(const DigitalPublication& other)
    : Publication(other), fileSize(other.fileSize), format(other.format)
{
    ++electronicCount;
}

DigitalPublication& DigitalPublication::operator=(const DigitalPublication& other)
{
    if (this == &other) return *this;
    Publication::operator=(other);
    fileSize = other.fileSize;
    format = other.format;
    return *this;
}

DigitalPublication::~DigitalPublication() {}

void DigitalPublication::getShortInfo() const
{
    std::cout << "Digital: \"" << title << "\", " << fileSize << " МБ, "
              << format << ", ISBN: " << isbn << "\n";
}