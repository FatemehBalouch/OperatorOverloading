#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100; // حداکثر تعداد کتاب‌ها

class Book {
private:
    string title;
    string author;
    int year;
    bool available;

public:
    // سازنده پیش‌فرض
    Book() : title(""), author(""), year(0), available(false) {}

    // سازنده با پارامتر
    Book(string t, string a, int y) : title(t), author(a), year(y), available(true) {}

    // توابع getter
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getYear() const { return year; }
    bool isAvailable() const { return available; }

    // توابع setter
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setYear(int y) { year = y; }
    void setAvailable(bool a) { available = a; }

    // نمایش اطلاعات کتاب
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (available ? "Available" : "Borrowed") << endl;
        cout << "---------------------" << endl;
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int count;

public:
    Library() : count(0) {}

    // اضافه کردن کتاب جدید
    void addBook(string title, string author, int year) {
        if (count < MAX_BOOKS) {
            books[count] = Book(title, author, year);
            count++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full! Cannot add more books." << endl;
        }
    }

    // نمایش همه کتاب‌ها
    void displayAllBooks() const {
        if (count == 0) {
            cout << "No books in the library." << endl;
            return;
        }

        cout << "Library Books:" << endl;
        cout << "---------------------" << endl;
        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }

    // جستجوی کتاب بر اساس عنوان
    void searchByTitle(string title) const {
        bool found = false;
        for (int i = 0; i < count; i++) {
            if (books[i].getTitle() == title) {
                books[i].display();
                found = true;
            }
        }

        if (!found) {
            cout << "Book with title \"" << title << "\" not found." << endl;
        }
    }

    // امانت گرفتن کتاب
    void borrowBook(string title) {
        for (int i = 0; i < count; i++) {
            if (books[i].getTitle() == title) {
                if (books[i].isAvailable()) {
                    books[i].setAvailable(false);
                    cout << "Book \"" << title << "\" borrowed successfully." << endl;
                } else {
                    cout << "Book \"" << title << "\" is already borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book \"" << title << "\" not found." << endl;
    }

    // پس دادن کتاب
    void returnBook(string title) {
        for (int i = 0; i < count; i++) {
            if (books[i].getTitle() == title) {
                if (!books[i].isAvailable()) {
                    books[i].setAvailable(true);
                    cout << "Book \"" << title << "\" returned successfully." << endl;
                } else {
                    cout << "Book \"" << title << "\" was not borrowed." << endl;
                }
                return;
            }
        }
        cout << "Book \"" << title << "\" not found." << endl;
    }
};

int main() {
    Library lib;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by Title" << endl;
        cout << "4. Borrow Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // برای حذف enter از بافر
switch (choice) {
            case 1:
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                lib.addBook(title, author, year);
                break;
            case 2:
                lib.displayAllBooks();
                break;
            case 3:
                cout << "Enter book title to search: ";
                getline(cin, title);
                lib.searchByTitle(title);
                break;
            case 4:
                cout << "Enter book title to borrow: ";
                getline(cin, title);
                lib.borrowBook(title);
                break;
            case 5:
                cout << "Enter book title to return: ";
                getline(cin, title);
                lib.returnBook(title);
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
