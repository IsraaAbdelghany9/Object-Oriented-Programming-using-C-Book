#include <iostream>
#include <sstream>
#include <string>
#include <cstdlib>
using namespace std;

class date
{
    int year;
    int month;
    int day;

public:
    void getdata()
    {
        string inputDate;
        char delimiter;

        cout << "Enter the date (MM/DD/YYYY): ";
        cin >> inputDate;

        stringstream ss(inputDate);
        ss >> month >> delimiter >> day >> delimiter >> year;

        if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
        {
            cout << "Invalid date format!" << endl;
            exit(1);
        }
    }
    void showdata()
    {
        cout << month << "/" << day << "/" << year << endl;

    }
};

class publication
{
    string title;
    float price ;

public:
    virtual void getdata()
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    virtual void putdata()
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << "$" << endl;
    }

};




class book : public publication
{
    int pageCount;
public:
    void getdata()
    {
        publication::getdata();
        cout << "The page count is " ;
        cin >> pageCount;
    }
    void putdata() const
    {
        publication::putdata();
        cout << "The playing time is ";
        cout << pageCount << endl;
    }
};

class tape : public publication
{
    float playingTime;
public:
    void getdata()
    {
        publication::getdata();
        cout << "Enter the playing time in minutes" ;
        cin >> playingTime;
    }
    void putdata() const
    {
        publication::putdata();
        cout << "The playing time in minutes = " <<playingTime << endl;
    }


};


int main()
{
    int size_;
    cout << "How many publications you want to add? \n>>>";
    cin >> size_;
    publication *pubs[size_] ;// = new publication[size];

    for (int i = 0; i < size_; i++) {
        char choice;
        while (true)
        {
            cout << "What do you want to enter, Book (B) or Tape (T)?  \n>>> ";
            cin >> choice;
            cin.ignore();
            if (choice == 'B' || choice == 'b') {
                pubs[i] = new book;
                break;
            } else if (choice == 'T' || choice == 't') {
                pubs[i] = new tape;
                break;
            } else {
                cout << "Invalid choice! Please enter B for Book or T for Tape." << endl;
            }
        }

        pubs[i]->getdata();
    }


    cout << "\nDisplaying all publications:\n";
    for (int i = 0; i < size_; i++) {
        pubs[i]->putdata();
        cout << endl;
    }

    for (int i = 0; i < size_; i++) {
        delete pubs[i];
    }

    return 0;
}
