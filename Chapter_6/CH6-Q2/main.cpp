#include <iostream>
#include<conio.h>
#include <windows.h>

using namespace std;
//charge = 50 cent
class tollbooth
{
    //static
    unsigned int totalCarNumber ;
    double totalMoney ;
public:
    tollbooth() : totalCarNumber(0) , totalMoney (0) {}

    void payingCar()
    {
        totalCarNumber++ ;
        totalMoney += 0.5 ;
    }

    void nonPayCar() { totalCarNumber++ ; }

    void display() { cout << "total Cars is : " << totalCarNumber << " total Money is : " << totalMoney <<endl; }
};

void printMenu();

int main()
{
    tollbooth t;

    while(true)
    {
        system("cls");
        printMenu();
        char key = _getch() ;

        if (key == 'p' || key == 'P')
        {
            t.payingCar();
            cout << "Paying car counted\n";
        }
        else if (key == 'n' || key == 'N')
        {
            t.nonPayCar();
            cout << "Non paying car\n";
        }

        else if (key == 27)
        {
            t.display() ;
            return 0 ;
        }
        else
            cout << "Invalid char entered\n" ;

        cout << "Press key to continue .....";
        _getch();

    }


}

void printMenu()
{
    cout << "Press N for adding non payed car \n";
    cout << "Press P for adding payed car \n";
    cout << "Press ESC to exit the program \n";

}
