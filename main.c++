#include <iostream>
#include <string>
#include <cstdlib> // for generating random IDs
#include <ctime> // for seeding random number generator

using namespace std;

//Parent class LibraryItem

class LibraryItem {
    protected:
        string title;
        int ID;
        string journalTitle;
    public:
        LibraryItem() {
            ID = rand(); //to generate a random ID
        }
    virtual void display() const {
        cout << "ID: " << ID << endl;
    }
};

class Book : public LibraryItem {
    private:
        string author;
        int year;
    public:
        Book(string t, string a, int y) {
            title = t;
            author = a;
            year = y;
        }

        void display() const override {
            LibraryItem :: display();
            cout << "Title: " << title << endl;
            cout << "Author: " << author << ", Year: " << year << endl;
        }
};

class Journal : public LibraryItem {
    private:
        int volume;
        string journalTitle;
    public:
        Journal(string t, int v) {
            journalTitle = t;
            volume = v;
        }

        void display() const override {
            LibraryItem::display();
            cout << "Title: " << journalTitle << endl;
            cout << "Volume: " << volume << endl;
        }
};

class LibraryManager {
    public:
        static void checkOut(LibraryItem& item) {
            cout << "Checking out item: ";
            item.display();
        }
        static void checkIn(LibraryItem& item) {
            cout << "Checking in item: ";
            item.display();
        }
};

int main() {

    string title, author, journalTitle;
    int year, volume;
    int choice;
    //seed the random number generator
    srand(time(NULL));
    // prompt the user for the information
    cout << "Do you want a book or journal? "<< endl;
    cout << "1. Book" << endl;
    cout << "2. Journal" << endl;
    cout << "3. Exit" << endl;
    cin >> choice;

    if (choice == 1) {
            cout << "Enter the title of the book: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter the author of the book: ";
            getline(cin, author);
            cout << "Enter the year of publication: ";
            cin >> year;

            Book book1(title, author, year);
            LibraryManager::checkIn(book1);
        } else if (choice == 2) {   
            cout << "Enter the title of the journal: ";
            cin.ignore();//ignore the newling character left in the buffer
            getline(cin, journalTitle);
            cout << "Enter the volume number of the journal: ";
            cin >> volume;

            Journal journal1(journalTitle, volume);
            LibraryManager::checkIn(journal1);
        } else if (choice == 3) {
            cout << "Thankyou for accessing this library";
            return 0;
        }    
    return 0;
}