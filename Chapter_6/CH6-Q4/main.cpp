#include <iostream>

using namespace std;

class employee
{
    int number;
    float compensation;

public:

    void setNumber(int _number) { number=_number;}
    void setCompensation(float _compensation) { compensation=_compensation;}

    int getNumber() {return number;}
    float getCompensation() {return compensation;}

    void display()
    {
        cout << "Number = " << this->number << " ,Compensation = " << compensation <<endl;
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
        cout<<"enter employee number " << i << endl;
        cin >> num >> f ;
        arr[i].setNumber(num);
        arr[i].setCompensation(f);
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        arr[i].display();
    }

    return 0;
}
