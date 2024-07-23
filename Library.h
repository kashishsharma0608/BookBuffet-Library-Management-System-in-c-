#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const Book& book);
    void removeBook(const std::string& title);
    void listBooks() const;
    void searchBookByTitle(const std::string& title) const;
};

#endif
