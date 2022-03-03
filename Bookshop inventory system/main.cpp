#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
#include<cstdbool>
using namespace std;

class Book {
    private:
        string name;
        int pages, inventory, id;
    public:
        //setter
        void setName ();
        void setPages ();
        void setInventory ();

        //set file
        void addBook ();
        void setFile (int);

        //getter
        string getName ();
        int getPages ();
        int getID ();
        int getInventory ();    

        //get file   
        void getBook ();
};
void presentation(int &);
int main () {
    
    int choice, many;
    bool loop = 1;

    while(loop) {
        presentation(choice);
        if (choice == 0) {
            loop = 0;
        }
        else if (choice == 1) {
            Book newBook;

            newBook.setName();
            newBook.setPages();
            newBook.setInventory();
            newBook.addBook();
        }
        else if (choice == 2) {
            Book buyBook;
            cout<< "how much book do you want to buy: "; cin>> many;
            if (many > 0) buyBook.setFile(many*-1);
        }
        else if (choice == 3) {
            Book sellBook;
            cout<< "how much book do you want to sell: "; cin>> many;
            if (many > 0) sellBook.setFile(many);
        }
        else if (choice == 4) {
            Book bookinfo;
            bookinfo.getBook();
        }
        else {
            cout<< "enter a correct choice!!!"<< endl;
        }
    }
}
/*setter*/
void Book::setName () {
    cout<< "enter book\'s name: "; cin>> name;
}
void Book::setPages () {
    cout<< "enter pages\'s number: "; cin>> pages;
}
void Book::setInventory () {
    cout<< "enter inventory\'s space: "; cin>> inventory;
}
void Book::addBook () {

    fstream fout(getName(), ios::out);
    int id = getID();

    fout<< "ID: "<< id<< endl;
    fout<< "Name: "<< getName()<< endl;
    fout<< "Pages: "<< getPages()<< endl;
    fout<< "Inventory: "<< getInventory()<< endl;
    
}
void Book::setFile (int method) {

    int counter = 0;
    char *info = new char[100]; 

    setName ();

    fstream fin(getName(), ios::in);
    while (fin>> info) {

        counter++;

        if (counter == 8) {
            if (method < 0 && atoi(info) >= method*-1) inventory = atoi(info) + method;
            else if (method > 0) inventory = atoi(info) + method;
            else return;
        }
        else if (counter == 2)
            id = atoi(info);
        else if (counter == 6) 
            pages = atoi(info);
            
        if (counter == 8) {
            fstream fout(getName(), ios::out);
                
            fout<< "ID: "<< id<< endl;
            fout<< "Name: "<< getName()<< endl;
            fout<< "Pages: "<< pages<< endl;
            fout<< "Inventory: "<< inventory<< endl;    
        }         
    }
 

    cout<< "done successfully, thanks"<< endl;    
}
/*getter*/
string Book::getName () {
    return name;
}
int Book::getPages () {
    return pages;
}
int Book::getID () {
    srand(time(0));
    return (rand()%99999);
}
int Book::getInventory () {
    return inventory;
}
void Book::getBook () {

    int counter = 0;
    string bookInfo;
    setName();

    fstream fin(getName(), ios::in);
    while (fin>> bookInfo) {
        counter++;
        if (counter % 2 == 0)
            cout<< bookInfo<< endl;
        else 
            cout<< bookInfo<< ' ';
    }
}
/*main functions*/
void presentation(int &choice) {
    cout<< "\n0.exit"<< endl;
    cout<< "1.add book or new informations"<< endl;
    cout<< "2.buy book"<< endl;
    cout<< "3.sell book"<< endl;
    cout<< "4.get book information"<< endl;
    cout<< "enter your choice: "; cin>> choice;
}
