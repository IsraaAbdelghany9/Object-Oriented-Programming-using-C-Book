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
        cin.ignore();

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

class employee
{
    int number;
    float salary;
    date hiredDate;
    char etype[30];

public:

    void putemploy()
    {
        cout << "Enter employee number: ";
        cin >> number;

        cout << "Enter employee salary: ";
        cin >> salary;

        cout << "Enter employee type (e.g., laborer , secretary , manager , etc ): ";
        cin >> etype;

        hiredDate.getdata();
    }

    void setNumber(int _number) { number=_number;}
    void setSalary(float _salary) { salary=_salary;}

    int getNumber() {return number;}
    float getSalary() {return salary;}

    void display()
    {
        cout << "Number = " << number << " ,Salary = " << salary << " ,hired data = "  ;
        hiredDate.showdata();

    }
};

int main()
{
    employee arr[3];
    cout << "enter 3 employees" << endl;
    int num;
    float f;
    for(int i = 0 ; i < 3 ; i++)
    {
        cout<<"enter employee number " << i+1 << endl;
        arr[i].putemploy();
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        arr[i].display();
    }

    return 0;
}
