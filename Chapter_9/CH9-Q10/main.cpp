#include <iostream>
#include <string>
using namespace std;

class employee {
    string name;
    string number;

public:
    void getdata()
    {
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter number: ";
        getline(cin, number);
    }

    void putdata() const
    {
        cout << "Name: " << name << endl;
        cout << "Number: " << number << endl;
    }
};

class employee2 : public employee {

    double compensation;
    enum period {HOURLY, WEEKLY, MONTHLY};
    period payPeriod;

public:
    void getdata() {
        employee::getdata();
        cout << "Enter compensation: ";
        cin >> compensation;
        while (true)
        {
            cout << "Enter payment period (0=Hourly, 1=Weekly, 2=Monthly): ";
            int choise;
            cin >> choise;
            if (choise == 0)
            {
                payPeriod = HOURLY;
                break;
            }
            else if (choise == 1)
            {
                payPeriod = WEEKLY;
                break;
            }
            else if (choise == 2)
            {
                payPeriod = MONTHLY;
                break;
            }
            else
                cout << "invalid input " << endl;
        }
        cin.ignore();  // to ignore the newline left by cin
    }

    void putdata() const {
        employee::putdata();
        cout << "Compensation: " << compensation << endl;
        cout << "Payment Period: ";
        switch (payPeriod) {
            case HOURLY: cout << "The Payment Period is Hourly"; break;
            case WEEKLY: cout << "The Payment Period is Weekly"; break;
            case MONTHLY: cout << "The Payment Period is Monthly"; break;
        }
        cout << endl;
    }
};

class manager2 : public employee2 {
    string title;
public:
    void getdata() {
        employee2::getdata();
        cout << "Enter title: ";
        getline(cin, title);
    }

    void putdata() const {
        employee2::putdata();
        cout << "Title: " << title << endl;
    }
};

class executive : protected manager2
{
    float bonus;
    double stockShared;
public:
    void getdata() {
        cout << "You are in executive class ^_^\n"
        manager2::getdata();
        cout << "Enter bonus: ";
        cin >> bonus ;
        cout << "Enter stock shared by the manager : " ;
        cin >> stockShared ;
    }

    void putdata() const {
        manager2::putdata();
        cout << "Bonus is : " << bonus << endl;
        cout << "Stock shared is : " << bonus << endl;
    }
};

int main() {
/*
    manager2 m;
    scientist2 s;
    laborer2 l;

    cout << "Enter data for manager:\n";
    m.getdata();
    cout << "\nEnter data for scientist:\n";
    s.getdata();
    cout << "\nEnter data for laborer:\n";
    l.getdata();

    cout << "\nDisplaying data for manager:\n";
    m.putdata();
    cout << "\nDisplaying data for scientist:\n";
    s.putdata();
    cout << "\nDisplaying data for laborer:\n";
    l.putdata();
*/
    executive e1;
    e1.getdata();
    e1.putdata();
    return 0;
}