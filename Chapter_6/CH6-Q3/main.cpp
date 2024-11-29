#include <iostream>

using namespace std;



class time
{
    int seconds ;
    int minutes ;
    int hours ;

public:

/////////////////////// Setters ////////////////////////
    void setSecond(int _seconds)
    {
        if (_seconds < 60 )
            seconds=_seconds;

        else
        {
            minutes += (_seconds / 60);
            seconds = _seconds % 60;
            if (minutes >= 60)
            {
                int extraHours;
                extraHours = minutes / 60;
                minutes = minutes % 60 ;
                hours += extraHours;
            }
        }
    }

    void setMinutes(int _minutes)
    {
        if (_minutes >= 60)
            {
                int extraHours;
                extraHours = _minutes / 60;
                minutes = _minutes % 60 ;
                hours += extraHours;
            }

        else
            minutes = _minutes;
    }

    void setHours(int _hours)
    {
        hours = _hours;
    }

/////////////////////// Getters ////////////////////////

    int getSeconds()
    {
        return seconds;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getHours()
    {
        return hours;
    }

//////////////////////// Print //////////////////////////////////////
/*
    void display()
    {
        if (hours == 0 && minutes == 0 && seconds == 0)
            cout << "The Duration is set to 0" << endl;

        if (hours == 0 && minutes == 0)
            cout << "Seconds :" << seconds << endl;

        else if (hours == 0 )
            cout << "Minutes :" <<minutes << "," << " Seconds :" << seconds << endl;

        else
            cout << "Hours :" << hours << ","  <<" Minutes :" <<minutes << "," << " Seconds :" << seconds << endl;

    else
        cout << setfill('0') << setw(2) << hours << ":"
             << setfill('0') << setw(2) << minutes << ":"
             << setfill('0') << setw(2) << seconds << endl;
    }
*/
    void display()
    {
        if (hours == 0 && minutes == 0 && seconds == 0)
        {
            cout << "The Duration is set to 0" << endl;
            return;
        }

        if (hours < 10)
            cout << "0";
        cout << hours << ":";

        if (minutes < 10)
            cout << "0";
        cout << minutes << ":";

        if (seconds < 10)
            cout << "0";
        cout << seconds << endl;
    }

//////////////////////////////////Operator Overload ///////////////////////////////


    time operator + (const time& d)
    {
        time res;
        res.setHours(hours + d.hours);
        res.setMinutes( minutes + d.minutes);
        res.setSecond(seconds + d.seconds);
        return res;
    }


/////////////////////////// Constructors /////////////////////////////

    time() // parameterless
    {
        hours = minutes = seconds = 0;
    }


    time(int _hours , int _minutes , int _seconds) // three parameter
    {
        hours = _hours;
        minutes = _minutes ;
        setSecond(_seconds);// _seconds;
    }


};


int main()
{

    time d1(1,10,15) ,d2 ;

    time d5 = d1 + d2 ; //  2 : 10 : 15 // correct
    d5.display();



    return 0;
}


