#include "Book.h"
#include <iostream>

Book::Book(const std::string& title, const std::string& author, int year)
    : title(title), author(author), publicationYear(year), isAvailable(true) {}

std::string Book::getTitle() const {
    return title;
}

std::string Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setAvailability(bool availability) {
    isAvailable = availability;
}

void Book::displayInfo() const {
    std::cout << "Title: " << title << "\n"
              << "Author: " << author << "\n"
              << "Year: " << publicationYear << "\n"
              << "Available: " << (isAvailable ? "Yes" : "No") << "\n";
}
