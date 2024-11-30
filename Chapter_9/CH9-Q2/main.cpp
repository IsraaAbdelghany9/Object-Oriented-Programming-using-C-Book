#include <iostream>
#include <cstring> //for strcpy(), etc.
using namespace std;

class String //base class
{
protected:

    enum { SZ = 80 };  //static const int SZ = 80; this is the equivalent
    char str[SZ];

public:
    String() { str[0] = '\0'; }
    String(char s[]){ strcpy(str, s); }

    void display() const
    {
        if (str[0]!= '\0')
            cout << str;
        else
            cout << "The string is too long " << endl;
    }

    operator char*() { return str; }
};

class Pstring : public String //derived class
{
public:
    Pstring( char s[] ) //constructor for Pstring
    {
        if(strlen(s) > SZ-1) //if too long,
        {
            for(int j=0; j<SZ-1; j++)
            {
                str[j] = s[j];
                str[j] = '\0';
            }
        }
        else
            strcpy(str, s);
    }
};


int main()
{
    Pstring s1 ("This is a very long string which is probably" "no, certainly--going to exceed the limit set by SZ." );
    cout << "\ns1="; s1.display();
    Pstring s2 = "This is a short string hahaha.";
    cout << "\ns2=";
    s2.display();
    cout << endl;
    return 0;
}
