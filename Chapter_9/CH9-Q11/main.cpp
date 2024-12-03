#include <iostream>
using namespace std;
#include <cstdlib>

class Stack
{
protected:
    enum { MAX = 3 };
    int st[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(int var)  { st[++top] = var; }

    int pop()  { return st[top--]; }
};


class Stack2 : public Stack
{
public:
    void push(int var)
    {
        if(top >= MAX-1)
        {
            cout << "\nError: stack is full";
            exit(1);
        }
        Stack::push(var);
    }

    int pop()
    {
        if(top < 0)
        {
             cout << "\nError: stack is empty\n";
             exit(1);
        }
        return Stack::pop();
    }
};

struct pair_
{
    int x, y;
};

class pairStack : protected Stack2
{
public:
    void push( pair_ p)
    {
        Stack2::push(p.x);
        Stack2::push(p.y);
    }

    pair_ pop()
    {
        pair_ p;
        p.y = Stack2::pop();
        p.x = Stack2::pop();

        return p;
    }
};
int main()
{
    pairStack p2;
    pair_ p1 = {1,2};
    p2.push(p1);
    pair_ p3 = p2.pop();
    cout << "pop x" << p3.x << endl;
    cout << "pop y" << p3.y << endl;
    return 0;
}
