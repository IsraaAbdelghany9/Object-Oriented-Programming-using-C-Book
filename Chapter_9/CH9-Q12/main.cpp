#include <iostream>
#include <numeric>
using namespace std;

class sterling {
protected:
    int pounds;
    int shillings;
    int pence;

public:
    sterling() : pounds(0), shillings(0), pence(0)
    {}

    sterling(int _pounds, int _shillings, int _pence) : pounds(_pounds), shillings(_shillings), pence(_pence)
    {}

    void display()
    {
        cout << "\u00A3" << pounds << "." << shillings << "." << pence;
    }
};

class sterfrac : protected sterling
{
    int eights ;

public:
    sterfrac(int _pounds, int _shillings, int _pence, int _eights):sterling(_pounds , _shillings , _pence) , eights(_eights)
    {}
    sterfrac():sterling() , eights(0)
    {}

    sterfrac operator + (const sterfrac& s)
    {
        sterfrac result(pounds + s.pounds, shillings + s.shillings, pence + s.pence, eights + s.eights);
        result.normalize();
        return result;
    }

    sterfrac operator - ( const sterfrac& s)
    {
        sterfrac result(pounds - s.pounds, shillings - s.shillings, pence - s.pence, eights - s.eights);
        result.normalize();
        return result;
    }

    sterfrac operator ++ ()
    {
        pounds = pounds + 1;
        return *this;
    }

    sterfrac operator -- ()
    {
        pounds = pounds - 1;
        return *this;
    }


    void display()
    {
        sterling::display();
        int numerator = eights;
        int denominator = 8;
        int gcd = calculate_gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (numerator != 0)
        {
            cout << "-" << numerator << "/" << denominator;
        }
    }

    void normalize()
    {
        if (eights >= 8) {
            pence += eights / 8;
            eights %= 8;

        }
        if (pence >= 12) {
            shillings += pence / 12;
            pence %= 12;
        }
        if (shillings >= 20) {
            pounds += shillings / 20;
            shillings %= 20;
        }
    }
};

int main()
{
    sterfrac s1(9, 19, 11, 7);
    sterfrac s2(1, 2, 3, 2);

    sterfrac result = s1 + s2;

    result.display();
    return 0;
}

int calculate_gcd(int a, int b)
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//////////////////£Pounds.Shillings.Pence-Fraction
