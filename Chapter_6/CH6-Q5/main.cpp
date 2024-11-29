#include <iostream>
#include <sstream>
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

    }
    void showdata()
    {
        cout << month << "/" << day << "/" << year << endl;

    }
};
int main()
{
    date d;
    d.getdata();
    d.showdata();
    return 0;
}
