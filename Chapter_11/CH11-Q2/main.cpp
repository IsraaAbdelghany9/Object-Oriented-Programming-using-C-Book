#include <iostream>

using namespace std;

class Distance
{
    int feet;
    float inches;
public:
    Distance(): feet(0), inches(0)
    {}

    Distance(float fltfeet)
    {
        feet = static_cast<int>(fltfeet);
        inches = 12*(fltfeet-feet);
    }

    Distance(int ft, float in) : feet(ft), inches(in)
    {}

    void showdist()
    {
        cout << feet << "\'-" << inches << '\"' << endl;
    }

    friend Distance operator * (Distance, Distance); //friend
};
int main()
{
    Distance d1(1, 1.0), d2(1, 1.0), d3;

    d3 = d1 * d2;
    d3.showdist();
    d3 = d1*2 ;
    d3.showdist();
    d3 = d2 *2 ;
    d3.showdist();


    return 0;
}

Distance operator * (Distance d1, Distance d2)
{
    float feet1_float = d1.feet + d1.inches/12;
    float feet2_float = d2.feet + d2.inches/12;
    Distance result (feet1_float * feet2_float);
    return result;
}
