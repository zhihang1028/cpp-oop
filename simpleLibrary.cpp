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
    Book **bookArray = nullptr; // to store pointer in array
    int capacity;
    int currentSize = 0;

    public:
    Library(int _capacity) : capacity(_capacity) {bookArray = new Book*[capacity];}
    ~Library(){delete [] bookArray;}

    void addBook(Book *&bookPtr){ // pass in book by reference
        if (currentSize < capacity){
            bookArray[currentSize] = bookPtr;
            currentSize ++;
            cout << bookPtr->getTitle() << " added successfully." << endl;
        }
        else
            cout << "Library is full. Unable to add " << bookPtr->getTitle() << endl;
    }

    void removeBook(int bookIndex){
        if (bookIndex - 1 < currentSize){
            cout << bookArray[bookIndex - 1]->getTitle() << " is successfully removed." << endl;
            for (int i = bookIndex - 1; i < currentSize - 1; i++){
                bookArray[i] = bookArray[i + 1];
                }
            currentSize--;
        } else
            cout << " Invalid index. Unable to remove." << endl;
    }

    void displayBooks()const {
        cout << "Books available: " << endl;
        for (int i = 0; i < currentSize; i++){
            cout << i + 1 << ". ";
            bookArray[i]->displayInfo();
            //cout << books[i].getTitle() << endl;
        }
    }

    int getSize()const {return currentSize;}
    
};

int main(){

    bool exit = false;
    //Book book1("BookA", "AuthorA", 2000), book2("BookB", "AuthorB", 2001);
    int libSize = 0;

    cout << "Please enter your library capacity: " << endl;
    cin >> libSize;

    Library library(libSize);

    while (!exit){  //Program loop

        int option;

        cout << "Welcome to library." << endl;
        cout << "1. Add book" << endl;
        cout << "2. Remove book" << endl;
        cout << "3. Display books\n" << endl;

        cout << "0. Exit program\n" << endl;

        cout << "Please enter an option:\n" << endl;

        cin >> option;
        cin.ignore();   // clear \n after cin

        switch (option){
            
            case 1:{
                string addTitle, addAuthor;
                int addYear;

                cout << "Enter the details of book you want to add: \n" << endl;
                cout << "Title: " << endl;
                getline(cin, addTitle);

                cout << "Author: " << endl;
                getline(cin, addAuthor);

                cout << "Publish year: " << endl;
                cin >> addYear;
                cin.ignore();

                Book *newBook = new Book(addTitle, addAuthor, addYear);
                library.addBook(newBook);
  
                break;
            }

            case 2:{
                int removeBook;
                if (library.getSize() > 0){
                    cout << "Which book do you want to remove?" << endl;
                    library.displayBooks();
                    
                    cin >> removeBook;
                    cin.ignore();

                    library.removeBook(removeBook);
                } else
                    cout << "Library is empty. Unable to remove books." << endl;
                break;
            }

            case 3:{
                cout << "Current number of books in library: " << library.getSize() << endl;
                if (library.getSize() > 0)
                    library.displayBooks();
                break;
            }
            case 0:{
                exit = true;
                break;
            }
            default:
                cout << "Invalid option." << endl;
                break;
        }

        if (exit)
        break;
    }
    
    return 0;
}