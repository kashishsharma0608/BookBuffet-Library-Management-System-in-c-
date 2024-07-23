#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title;
    std::string author;
    int publicationYear;
    bool isAvailable;

public:
    Book(const std::string& title, const std::string& author, int year);
    
    std::string getTitle() const;
    std::string getAuthor() const;
    int getPublicationYear() const;
    bool getAvailability() const;
    
    void setAvailability(bool availability);
    void displayInfo() const;
};

#endif
