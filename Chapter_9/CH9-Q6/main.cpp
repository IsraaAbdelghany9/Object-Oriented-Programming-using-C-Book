#include <iostream>
using namespace std;
#include <cstdlib>

const int LIMIT = 100;

class safe_array
{
protected:
    int arr[LIMIT];

public:
    void putel(int n, int elvalue)
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        arr[n] = elvalue;
    }
    int getel(int n) const
    {
        if( n< 0 || n>=LIMIT )
        {
            cout << "\nIndex out of bounds";
            exit(1);
        }
        return arr[n];
    }
};

class safehilo : public safe_array
{
    int lower;
    int upper;

public:
    safehilo(int _lower, int _upper) : lower(_lower), upper(_upper)
    {}

    void putel(int n, int elvalue) {
        if (n < lower || n >= upper) {
            cout << "\nIndex " << n << " out of bounds <valid range is : " << lower << " to " << upper - 1 << ">" <<endl;
            exit(1);
        }
        arr[n] = elvalue;
    }

    int getel(int n) const
    {
        if (n < lower || n >= upper)
        {
            cout << "\nIndex " << n << " out of bounds <valid range is : " << lower << " to " << upper - 1 << ">" <<endl;
            exit(1);
        }
        return arr[n];
    }
};

int main()
{
    safehilo sa1(10,100);

    for(int j=10; j<100; j++)
        sa1.putel(j, j*10);

    for(int j=10; j<100; j++)
    {
        int temp = sa1.getel(j);
        cout << "Element " << j << " is " << temp << endl;
    }
    return 0;
}
