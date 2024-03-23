#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX_BOOKS = 10; // Maximum number of books in the library

class BookNode {
public:
    string title, author;
    int ISBN, availability;
};

BookNode library[MAX_BOOKS]; // Array to store book records
int totalBooks = 0; // Variable to keep track of the total number of books

BookNode* findBook(int key) {
    for (int i = 0; i < totalBooks; ++i) {
        if (library[i].ISBN == key) {
            return &library[i];
        }
    }
    return nullptr;
}

void insertBook() {
    int index;
    cout << "Enter the index where you want to insert the book (0-" << MAX_BOOKS - 1 << "): ";
    cin >> index;

    if (index < 0 || index >= MAX_BOOKS) {
        cout << "Invalid index.\n";
        return;
    }

    if (library[index].ISBN != 0) {
        cout << "Book already exists at index " << index << ".\n";
        return;
    }

    int key;
    cout << "Enter the ISBN of the book you want to insert: ";
    cin >> key;

    BookNode* existingBook = findBook(key);
    if (existingBook != nullptr) {
        existingBook->availability++;
    } else {
        library[index].ISBN = key;
        cout << "Enter the name of the book: ";
        cin >> library[index].title;
        cout << "Enter the author's name: ";
        cin >> library[index].author;
        library[index].availability = 1;

        totalBooks++;
    }
}

void deleteBook(int key) {
    for (int i = 0; i < totalBooks; ++i) {
        if (library[i].ISBN == key) {
            for (int j = i; j < totalBooks - 1; ++j) {
                library[j] = library[j + 1];
            }
            totalBooks--;
            cout << "Book with ISBN " << key << " deleted successfully.\n";
            return;
        }
    }
    cout << "Book with ISBN " << key << " not found.\n";
}

void searchBook(int key) {
    BookNode* foundBook = findBook(key);

    if (foundBook != nullptr) {
        cout << "Book found!\n";
        cout << "Title: " << foundBook->title << "\n"
             << "Author: " << foundBook->author << "\n"
             << "ISBN: " << foundBook->ISBN << "\n"
             << "Availability: " << foundBook->availability << " books are available\n\n";
    } else {
        cout << "Book with ISBN " << key << " not found.\n";
    }
}

void displayBooks() {
    cout << "--------------------------------------------------------------------------------------------------\n";
    cout << setw(5) << "Index" << setw(20) << "Title" << setw(20) << "Author" << setw(15) << "ISBN" << setw(15) << "Availability" << endl;
    cout << "--------------------------------------------------------------------------------------------------\n";
    for (int i = 0; i < MAX_BOOKS; ++i) {
        if (library[i].ISBN != 0) {
            cout << setw(5) << i << setw(20) << library[i].title << setw(20) << library[i].author << setw(15) << library[i].ISBN << setw(15) << library[i].availability << endl;
        } else {
            cout << setw(5) << i << setw(20) << "-" << setw(20) << "-" << setw(15) << "-" << setw(15) << "-" << endl;
        }
    }
    cout << "--------------------------------------------------------------------------------------------------\n";
}

int main() {
    int choice;
    
    do {
        cout << "1. Add book to library\n"
             << "2. Display book records in library\n"
             << "3. Delete book by ISBN\n"
             << "4. Search for book by ISBN\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                int deleteISBN;
                cout << "Enter ISBN to delete: ";
                cin >> deleteISBN;
                deleteBook(deleteISBN);
                break;
            case 4:
                int searchISBN;
                cout << "Enter ISBN to search: ";
                cin >> searchISBN;
                searchBook(searchISBN);
                break;
            default:
                cout << "Invalid choice\n";
        }

        cout << "Do you want to continue (1/0): ";
        cin >> choice;
    } while (choice == 1);

    return 0;
}
