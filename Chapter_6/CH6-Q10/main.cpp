#include <iostream>
#include <string.h>
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
        cout << "I am object number " << selfcounter ;
    }
    ~serialNumber()
    {
        counter--;
    }
};

int serialNumber::counter = 0 ;

class angle {
protected:
    int degrees;
    float minutes;
    char direction[2];    // Direction (N, S, E, W)
    char type[10];

public:
//////////////////////// Constructor ////////////////////////
    angle()
    {
        degrees = 0;
        minutes = 0;
        strcpy(direction, "E");
        strcpy(type , "No type");
    }
    angle( int _deg , float _min , char _dir[2] ,char _type[30] )
    {
        degrees = _deg;
        minutes = _min;
        strcpy(direction, _dir);
        strcpy(type , _type);
    }

    void displayAngle()
    {
        cout << degrees << "\xF8" << minutes << "' " << direction << endl;
    }

    void setDegree()
    {
        cout << "Enter degrees: ";
        while (true)
        {
            cin >> degrees;
            if (strcmp(type, "Longitude") == 0)
            {
                if (degrees >= 0 && degrees <= 180)
                    break;
                else
                    cout << "Invalid input. Longitude degrees must be between 0 and 180. Try again: ";
            }
            else if (strcmp(type, "Latitude") == 0)
            {
                if (degrees >= 0 && degrees <= 90)
                    break;
                else
                    cout << "Invalid input. Latitude degrees must be between 0 and 90. Try again: ";
            }
        }
    }
    void setType()
    {
        cout << "Enter type (Longitude/Latitude): ";
        while (true)
        {
            cin >> type;
            if (strcmp(type, "Longitude") == 0 || strcmp(type, "Latitude") == 0)
                break;
            else
                cout << "Invalid type. Please enter either 'Longitude' or 'Latitude': ";
        }
    }

    void setMinutes()
    {
        cout << "Enter minutes: ";
        while (true) {
            cin >> minutes;
            if (minutes >= 0 && minutes < 60) {
                break; // Valid minutes input
            } else {
                cout << "Invalid input. Minutes must be between 0 and 59. Try again: ";
            }
        }
    }

    void setDirection()
    {
        cout << "Enter direction (N/S/E/W): <should be capital letters> ";
        while (true)
        {
            cin >> direction;
            if (direction[0] == 'N' || direction[0] == 'S' || direction[0] == 'E' || direction[0] == 'W') {
                break;
            } else {
                cout << "Invalid direction. Please enter one of the following: N, S, E, W: ";
            }
        }
    }

};



class ship : public angle , public serialNumber
{};


int main()
{
    ship s[3];

    for (int i = 0 ; i < 3 ; i ++)
    {
        cout << "Enter ship number " << 1+i << endl;
        cout << "Enter type: ";
        s[i].setType();
        cout << "Enter degrees: ";
        s[i].setDegree();
        cout << "Enter minutes: ";
        s[i].setMinutes();
        cout << "Enter direction: ";
        s[i].setDirection();

    }

    for (int i = 0 ; i < 3 ; i ++)
    {
        s[i].printCounter();
        s[i].displayAngle();
    }

    return 0;
}
