#include <iostream>

using namespace std;

class serialNumber
{
    static int counter;
    int selfcounter ;
public:
    serialNumber()
    {
        counter++;
        selfcounter = counter ;
    }
    void printCounter()
    {
        cout << "I am object number " << selfcounter << endl;
    }
    ~serialNumber()
    {
        counter--;
    }
};

int serialNumber::counter = 0 ;

int main()
{
    serialNumber s1 , s2 , s3 ;
    s2.printCounter();
    s3.printCounter();
    return 0;
}
