#include <iostream>

using namespace std;

class Int
{
    int i;

public:

    void srti(int _i) { this->i = _i ;}
    int geti() { return i; }

    void InitializeByZero() { this->i = 0 ;}
    void InitializeByValue(int _i) { this->i = _i ;}

    Int Add2Ints(Int _y)
    {
         i = i + _y.i ;
         return *this;
    }



    void display()
    {
        cout << "int i is : " << i << endl;
    }
};

Int Add2IntsStandAlone(Int n, Int m);

int main()
{
    Int i, y, j;
    y.InitializeByValue(3);
    j.InitializeByZero();

    i = y.Add2Ints(j);
    i.display();
    cout << "Hello world!" << endl;
    return 0;
}

Int Add2IntsStandAlone(Int n, Int m)
{
    return n.Add2Ints(m);
}
