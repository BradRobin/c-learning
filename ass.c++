//BSE-05-0137/2022 BRAD ROBINSON
//using zetech system that has the following subsystems registration and accounts write
// a simple c++ program using classes to display the admission number, account balance
//and course done. Hint use constructors

#include <iostream>

using namespace std;

string bookt;
int id;
string author;
int year;
int volume;
bool checkedin;

class Libraryitem{
    private:
        string bookTitle;
        int ID;
    public:
        void setValues(){
            bookTitle = bookt;
            id = rand();
            ID = id;
        }

        void getValues(){
            cout << "Book Title: " << bookTitle;
            cout << "Book ID: " << ID;
        }        
};

class Book : public Libraryitem {
    private:
        string Author;
        int Year;
    public:
        void setValues(string author, int year){
            Author = author;
            Year = year;
        }

        void getValues(){
            cout << "Author: " << Author;
            cout << "Year: " << Year;
        }
};

class Journal : public Libraryitem {
    private:
        int Volume;
    public:
        void setVolume(int volume){
            Volume = volume;
        }
        void getVolume(){
            cout << "The Volume is: " << endl;
        }
};

class Manage : public Libraryitem {
    public:
        int daysToKeep;
};

int main(){
    int choice;
    cout << "Choose a library item";
    cout << "1. BOOK";
    cout << "2. JOURNAL";

    switch (choice)
    {
    case 1:
        Book book1;
        cout << "Enter name of book: ";
        cin >> bookt;
        cout << "Enter year of publication";
        cin >> year;
        book1.setValues(bookt, year);
        checkedin = true;
        book1.getValues();
        break;
    case 2:
        Journal journal1;
        cout << "Enter number of Journal: ";
        cin >> volume;
        journal1.setValues(volume);
        checkedin = true;
        journal1.getValues();
        break;
    default:
        break;
    }
    
    return 0;
}