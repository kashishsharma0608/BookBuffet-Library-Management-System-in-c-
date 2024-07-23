#include <iostream>
#include "Library.h"
#include "Book.h"
//g++ -o library_management BookBuffet.cpp Library.cpp Book.cpp
using namespace std;
int main() {
    Library library;

    int choice;
    std::string title, author;
    int year;

    while (true) {
        cout << "\nLibrary Management System\n"<< "1. Add Book\n"<< "2. Remove Book\n"<< "3. List Books\n" << "4. Search Book by Title\n"<< "5. Exit\n"<< "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(std::cin, title);
                cout << "Enter author: ";
                getline(std::cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                cin.ignore();
                library.addBook(Book(title, author, year));
                break;
            case 2:
                cout << "Enter title of book to remove: ";
                getline(std::cin, title);
                library.removeBook(title);
                break;
            case 3:
                library.listBooks();
                break;
            case 4:
                cout << "Enter title of book to search: ";
                getline(std::cin, title);
                library.searchBookByTitle(title);
                break;
            case 5:
                return 0;
            default:
            cout << "Invalid choice!\n";
        }
    }
}
