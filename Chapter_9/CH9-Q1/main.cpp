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
    void getdata()
    {
        cout << "Enter title: ";
        getline(cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void putdata() const
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
    publication pubs;
    pubs.getdata();
    pubs.putdata();

    cin.ignore();

    book b ;
    b.getdata();
    b.putdata();

    cin.ignore();

    tape t ;
    t.getdata();
    t.putdata();

    return 0;
}
