#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class sales
{
    float records[3];
public:
    void getdata()
    {
        for (int i = 0 ; i < 3 ; i ++ )
        {
            cout << "Enter the " << i << " record : " ;
            cin >> records[i];
        }

    }

    void putdata() const
    {
        for (int i = 0 ; i < 3 ; i ++ )
        {
            cout << "Enter the " << i << " record : "<< records[i] << endl;
        }

    }

};

class publication : private sales
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
        sales::getdata();
    }

    void putdata() const
    {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << "$" << endl;
        sales::putdata();
    }

};

class book : private publication
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

class tape : private publication
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

class disk : private publication
{
    enum DiskType { DVD, CD }; // Enum to represent disk types (DVD, CD)
    DiskType dtype; // Variable to store the disk type

public:
    void getdata()
    {
        publication::getdata();
        char choice;
        while (true)
        {
            cout << "Enter the disk type: 'd' for DVD, 'c' for CD: ";
            cin >> choice;
            if (choice == 'd' || choice == 'D')
            {
                dtype = DVD; // Assign enum value DVD
                break;
            }
            else if (choice == 'c' || choice == 'C')
            {
                dtype = CD; // Assign enum value CD
                break;
            }
            else
            {
                cout << "Invalid input, please enter (C or D): " << endl;
            }
        }
    }

    void putdata() const
    {
        publication::putdata();
        if (dtype == DVD)
            cout << "The disk type is: DVD" << endl;

        else if (dtype == CD)
            cout << "The disk type is: CD" << endl;

    }
};

int main()
{
/*
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
*/
    disk d ;
    d.getdata();
    d.putdata();

    return 0;
}
