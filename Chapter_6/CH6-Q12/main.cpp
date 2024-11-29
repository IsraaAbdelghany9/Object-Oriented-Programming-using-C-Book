#include <iostream>

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
    void setFraction(int _Num, int _Den)
    {
        Num = _Num;
        Den = _Den;
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
        if (Den == 1) cout << Num ;
        else if (Den == 0) cout << "The number is divided by zero";
        else if (Den == Num) cout << "1"  ;
        else if ( Den > 0 )cout << Num << "/" << Den ;

    }

//////////////////// Constructors ///////////////
    fractionNumber ()
    {
        Num = 0;
        Den = 1;
    }

//////////////////// Operator overload /////////////////////

    fractionNumber operator * (const fractionNumber & f) //f =  f1 * f2
    {
        fractionNumber res;
        res.Num = Num * f.Num ;
        res.Den = Den * f.Den ;

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

void separateByLine();
void printFirstLine(fractionNumber *arr , int n);

int main()
{
    int n ;
    cout << "Welcome to our program ^-^\n";
    cout << "Enter the dominator you want to generate the table for you ^_-\n>>>";
    cin >> n ;
    fractionNumber *arr = new fractionNumber[n];

    for(int i = 0 ; i < n ; i++)
        arr[i].setFraction(i,n);

    printFirstLine(arr ,n);

    for (int j = 0 ; j < n ; j++)
    {
        int w = 0 ;
        for(int w = 0 ; w < n ; w++)
        {
            if (w == 0 )
                arr[j].print();
            cout << "\t";
            fractionNumber f = arr[j]*arr[w];
            f.print();
        }
        cout << endl;
    }
    return 0;
}


void separateByLine()
{
    cout << "\n\t=============================================\n" << endl;
}

void printFirstLine(fractionNumber *arr , int n)
{
    for(int i = 0 ; i <= n ; i++)
        {
            if (i == n )
                separateByLine();
            else
            {
                if (i == 0 )
                    cout << "\t";
                arr[i].print();
                cout << "\t" ;
            }

        }
}
