#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// ANSI escape codes for colors
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string RESET = "\033[0m";

class Book {
private:
    string title;
    string author;
    bool isBorrowed;

public:
    Book(string t, string a, bool b = false) : title(t), author(a), isBorrowed(b) {}

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    bool getIsBorrowed() const {
        return isBorrowed;
    }

    void borrowBook() {
        if (!isBorrowed) {
            isBorrowed = true;
            cout << GREEN << "Book borrowed successfully." << RESET << endl;
        } else {
            cout << RED << "Book is already borrowed." << RESET << endl;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            cout << GREEN << "Book returned successfully." << RESET << endl;
        } else {
            cout << RED << "Book is not borrowed." << RESET << endl;
        }
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << book.title << '\n' << book.author << '\n' << book.isBorrowed << '\n';
        return os;
    }

    friend istream& operator>>(istream& is, Book& book) {
        getline(is, book.title);
        getline(is, book.author);
        is >> book.isBorrowed;
        is.ignore();
        return is;
    }
};

class Library {
private:
    vector<Book> books;
    const string databaseFile = "library_database.txt";

    void loadFromDatabase() {
        ifstream inFile(databaseFile);
        if (inFile.is_open()) {
            Book book("", "");
            while (inFile >> book) {
                books.push_back(book);
            }
            inFile.close();
        }
    }

    void saveToDatabase() const {
        ofstream outFile(databaseFile);
        if (outFile.is_open()) {
            for (const auto& book : books) {
                outFile << book;
            }
            outFile.close();
        }
    }

public:
    Library() {
        loadFromDatabase();
    }

    ~Library() {
        saveToDatabase();
    }

    void addBook(const string& title, const string& author) {
        books.emplace_back(title, author);
        cout << CYAN << "Book added successfully!" << RESET << endl;
        saveToDatabase();
    }

    void removeBook(const string& title) {
        auto it = remove_if(books.begin(), books.end(), [&](const Book& book) {
            return book.getTitle() == title;
        });

        if (it != books.end()) {
            books.erase(it, books.end());
            cout << CYAN << "Book removed successfully!" << RESET << endl;
            saveToDatabase();
        } else {
            cout << RED << "Book not found." << RESET << endl;
        }
    }

    void searchBook(const string& title) const {
        for (const auto& book : books) {
            if (book.getTitle() == title) {
                cout << BLUE << "Book found: " << RESET << book.getTitle() << " by " << book.getAuthor() << '\n';
                return;
            }
        }
        cout << RED << "Book not found." << RESET << endl;
    }

    void borrowBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.borrowBook();
                saveToDatabase();
                return;
            }
        }
        cout << RED << "Book not found." << RESET << endl;
    }

    void returnBook(const string& title) {
        for (auto& book : books) {
            if (book.getTitle() == title) {
                book.returnBook();
                saveToDatabase();
                return;
            }
        }
        cout << RED << "Book not found." << RESET << endl;
    }

    void listBooks() const {
        cout << CYAN << "Books in the library:" << RESET << endl;
        for (const auto& book : books) {
            cout << book.getTitle() << " by " << book.getAuthor() << (book.getIsBorrowed() ? " [Borrowed]" : " [Available]") << '\n';
        }
    }
};

int main() {
    Library library;
    int choice;
    string title, author;

    while (true) {
        cout << GREEN << "WELCOME TO BOOK BUFFET LIBRARY SYSTEM" << RESET << endl;
        cout << YELLOW << "1. Add Book" << RESET << endl;
        cout << YELLOW << "2. Remove Book" << RESET << endl;
        cout << YELLOW << "3. Search Book" << RESET << endl;
        cout << YELLOW << "4. Borrow Book" << RESET << endl;
        cout << YELLOW << "5. Return Book" << RESET << endl;
        cout << YELLOW << "6. List Books" << RESET << endl;
        cout << YELLOW << "7. Exit" << RESET << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << MAGENTA << "Enter book title: " << RESET;
                getline(cin, title);
                cout << MAGENTA << "Enter book author: " << RESET;
                getline(cin, author);
                library.addBook(title, author);
                break;
            case 2:
                cout << MAGENTA << "Enter book title to remove: " << RESET;
                getline(cin, title);
                library.removeBook(title);
                break;
            case 3:
                cout << MAGENTA << "Enter book title to search: " << RESET;
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                cout << MAGENTA << "Enter book title to borrow: " << RESET;
                getline(cin, title);
                library.borrowBook(title);
                break;
            case 5:
                cout << MAGENTA << "Enter book title to return: " << RESET;
                getline(cin, title);
                library.returnBook(title);
                break;
            case 6:
                library.listBooks();
                break;
            case 7:
                cout << CYAN << "Exiting... Have a great day!" << RESET << endl;
                return 0;
            default:
                cout << RED << "Invalid choice, please try again." << RESET << endl;
                break;
        }
    }

    return 0;
}
