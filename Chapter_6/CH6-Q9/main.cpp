#include <iostream>
#include <sstream>

using namespace std;


class fractionNumber
{
    int Num ;
    int Den ;

public:

/////////////////////// Setters ////////////////////////
    void setNum(int _Num)
    {
        Num=_Num;
    }
    void setDen(int _Den)
    {
        Den=_Den;
    }
    void setFraction()
    {
        string inputDate;
        char delimiter;
        cout << "Enter the number (Num/Den): ";
        cin >> inputDate;

        stringstream ss(inputDate);
        ss >> Num >> delimiter >> Den ;

    }
/////////////////////Getters//////////////////////////
    int getNum()
    {
        return Num;
    }
    int getDen()
    {
        return Den;
    }
//////////////////// Print ///////////////////////////
    void print()
    {
        simplify();
        if (Den == 1) cout << Num << endl;
        else if (Den == 0) cout << "The number is divided by zero"<< endl;
        else if (Den == Num) cout << "1" << endl ;
        else if ( Den > 0 )cout << "Number = "<< Num << "/" << Den << endl ;

    }

//////////////////// Constructors ///////////////
    fractionNumber ()
    {
        Num = 0;
        Den = 1;
    }

    fractionNumber (int _Num)
    {
        Num = _Num;
        Den = 1;
    }

    fractionNumber (int _Num , int _Den)
    {
        Num = _Num;
        Den = _Den;
    }

//////////////////// Operator overload /////////////////////

    fractionNumber operator + (const fractionNumber & f) //f =  f1 + f2  (done)
    {
        fractionNumber res;
        res.Num = Num * f.Den + f.Num * Den ;
        res.Den = Den * f.Den;

        return res;
    }

/////////////////////simplify the fraction /////////////////////////////////////////////
    void simplify()
    {
        int up = Num >= 0 ? Num : -Num; // Ensure the value of the Num is positive since we do not have ads fun
        int down = Den >= 0 ? Den : -Den; // Ensure the value of the den is +
        int divisor = 1;
        for(int i=1 ; i <= down && i <= up; ++i)
        {
            if(up%i==0 && down%i==0)
                 divisor = i ;
        }

        Num /= divisor;
        Den /= divisor;


        if (Den < 0) // ensure the den is + cuz
        {
            Num = -Num;
            Den = -Den;
        }

    }
};


int main()
{
    int n , m ;
    int flag = 1;
    while (flag != 0)
    {
        cout << "Welcome \n"<< endl;
        fractionNumber n1 , n2 , res;
        n1.setFraction();
        n2.setFraction();
        res = n1 + n2 ;
        cout << "The result is :" ;
        res.print();
        cout << "Do you want to continue? Press 1 for yes 0 for no :" ;
        cin >> flag;

        if (flag == 'Y' || flag == 'y')
            flag = 1;

        else if (flag == 'N' || flag == 'n')
        {
            cout << "See you soon!" << endl;
            flag = 0;
        }
    }
    return 0;
}
