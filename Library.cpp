#include "Library.h"
#include <iostream>

void Library::addBook(const Book& book) {
    books.push_back(book);
}

void Library::removeBook(const std::string& title) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->getTitle() == title) {
            books.erase(it);
            std::cout<<"Book Deleted\n";
            return;
        }
        
    }
    std::cout << "Book not found!\n";
}

void Library::listBooks() const {
    if (books.empty()) {
        std::cout << "No books available.\n";
        return;
    }
    for (const auto& book : books) {
        book.displayInfo();
    }
}

void Library::searchBookByTitle(const std::string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            book.displayInfo();
            return;
        }
    }
    std::cout << "Book not found!\n";
}
