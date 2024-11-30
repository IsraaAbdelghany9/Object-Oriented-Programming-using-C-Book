#include <iostream>
using namespace std;

class Counter
{
protected:
    unsigned int counter;

public:
    Counter() : counter(0)
    { }
    Counter(int c) : counter(c)
    { }
    unsigned int get_count() const
    { return counter; }
    Counter operator ++ ()
    { return Counter(++counter); }
};


class CountDn : public Counter
{
public:
    Counter operator -- ()
    { return Counter(--counter); }
};

class CountPostFix : public Counter
{

public:
    CountPostFix(int _n) : Counter(_n) {}
    Counter operator--(int)
    {
        Counter temp = *this;
        if (counter > 0)
            --counter;
        else
            cout << "Counter cannot go below 0." << endl;
        return temp;
    }
    Counter operator++(int) {
        Counter temp = *this;
        ++counter;
        return temp;
    }
};

int main()
{
    /*
    CountDn c1;
    cout << "\nc1=" << c1.get_count();

    ++c1; ++c1; ++c1;
    cout << "\nc1=" << c1.get_count();

    --c1; --c1;
    cout << "\nc1=" << c1.get_count() << endl;
    */
    CountPostFix c2(3);
    c2--;
    cout << "After postfix decrement : " << c2.get_count() << endl;

    c2++;
    cout << "After postfix increment : " << c2.get_count() << endl;
return 0;
}
