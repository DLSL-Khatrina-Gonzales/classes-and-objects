#include <iostream>
#include <iomanip>
using namespace std;

class Book {
private:
    string title, author;
    int year;

public:
    Book() : title(""), author(""), year(0) {}
    
    void setData(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    void display() const {
        cout << left << setw(30) << title << setw(25) << author << setw(4) << year << endl;
    }

    bool search(string t) const {
        return title == t;
    }

    string getTitle() const {
        return title;
    }

    string getAuthor() const {
        return author;
    }

    int getYear() const {
        return year;
    }
};

class AddBook {
private:
    Book books[100]; // Assuming a maximum of 100 books
    int bookCount;

public:
    AddBook() : bookCount(0) {}

    void addBook() {
        string title, author;
        int year;
        cout << "\nEnter title: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter year: ";
        cin >> year;

        books[bookCount].setData(title, author, year);
        bookCount++;
        cout << "Book added successfully!" << endl;
    }

    void displayBooks() const {
        if (bookCount == 0) {
            cout << "No books available!" << endl;
            return;
        }

        cout << "\nBook List:" << endl;
        cout << left << setw(30) << "Title" << setw(25) << "Author" << setw(4) << "Year" << endl;

        for (int i = 0; i < bookCount; i++) {
            books[i].display();
        }
    }

    void searchBook() const {
        string title;
        cout << "\nEnter a book to search: ";
        cin.ignore(); // To clear the input buffer
        getline(cin, title);

        for (int i = 0; i < bookCount; i++) {
            if (books[i].search(title)) {
                cout << "\nBook found!" << endl;
                cout << "Title: " << books[i].getTitle() << endl;
                cout << "Author: " << books[i].getAuthor() << endl;
                cout << "Year: " << books[i].getYear() << endl;
                return;
            }
        }
        cout << "\nBook not found!" << endl;
    }
};

int main() {
    AddBook library;
    int choice;

    do {
        cout << "\nMenu\n1 - Add Book\n2 - Display Books\n3 - Search Book\n4 - Exit\n";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.searchBook();
                break;
            case 4:
                cout << "\nExiting program..." << endl;
                break;
            default:
                cout << "\nInvalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}