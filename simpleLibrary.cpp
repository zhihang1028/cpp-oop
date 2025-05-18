#include <iostream>
#include <string>
using namespace std;

class Book{
    private:
    string title, author;
    int yearPublished;

    public:
    Book(const string &_title, const string &_author, const int &_yearPublished) : title(_title), author(_author), yearPublished(_yearPublished){}
    Book() : title(""), author(""), yearPublished(0){}
    string getTitle()const {return title;}
    string getAuthor()const {return author;}
    int getYear()const {return yearPublished;}
    void displayInfo()const {cout << "Title: " << title << ", Author: " << author << ", Year Published: " << yearPublished << endl;}

};

class Library{
    private:
    Book *books = nullptr;
    int capacity;
    int currentSize = 0;

    public:
    Library(int _capacity) : capacity(_capacity) {books = new Book[capacity];}
    ~Library(){delete [] books;}

    void addBook(const Book &book){ // pass in const book by reference
        if (currentSize < capacity){
            books[currentSize] = book;
            currentSize ++;
            cout << book.getTitle() << " added successfully." << endl;
        }
        else
            cout << "Library is full. Unable to add " << book.getTitle() << endl;
    }

    void removeBook(const Book &book){
        if (currentSize != 0){
            bool bookRemoved = 0;
            for (int i = 0; i < currentSize; i++){
                if (book.getTitle() == books[i].getTitle()){
                    for (int j = i; j < currentSize - 1; j++){
                        books[j] = books[j + 1];
                    }
                    currentSize--;
                    cout << book.getTitle() << " is successfully removed." << endl;
                    bookRemoved = 1;
                } 
            }
            if (!bookRemoved){
                cout << book.getTitle() << " is not in library. Unable to remove." << endl;
            }

        } else{
            cout << "Library is empty. Unable to remove books." << endl;
        }
    }

    void displayBooks()const {
        cout << "Books available: " << endl;
        for (int i = 0; i < currentSize; i++){
            books[i].displayInfo();
            //cout << books[i].getTitle() << endl;
        }
    }

    int getSize()const {return currentSize;}
    
};

int main(){

    bool exit = 0;
    Book book1("BookA", "AuthorA", 2000), book2("BookB", "AuthorB", 2001);
    Library library(10);

    while (1){  //Program loop

        int option;

        cout << "Welcome to library." << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Display books\n" << endl;

        cout << "0. Exit program\n" << endl;

        cout << "Please enter an option:\n" << endl;

        cin >> option;

        switch (option){
            case 1:
                int chooseBook;
                cout << "Which book do you want to add?" << endl;
                cout << "1. BookA" << endl;
                cout << "2. BookB" << endl;
                cin >> chooseBook;
                switch (chooseBook){
                    case 1:
                        library.addBook(book1);
                        break;
                    case 2:
                        library.addBook(book2);
                        break;
                }
                continue;

            case 2:
                int removeBook;
                cout << "Which book do you want to remove?" << endl;
                cout << "1. BookA" << endl;
                cout << "2. BookB" << endl;
                cin >> removeBook;
                switch (removeBook){
                    case 1:
                        library.removeBook(book1);
                        break;
                    case 2:
                        library.removeBook(book2);
                        break;
                }
                continue;

            case 3:
                cout << "Current number of books in library: " << library.getSize() << endl;
                if (library.getSize() > 0)
                    library.displayBooks();
                continue;
            case 0:
                exit = 1;
                break;
            default:
                continue;
        }

        if (exit)
        break;
    }
    
    return 0;
}