#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

class angle {
protected:
    int degrees;
    float minutes;
    char direction[2];    // Direction (N, S, E, W)
    char type[10];

public:
//////////////////////// Constructor ////////////////////////
    angle( int _deg , float _min , char _dir[2] ,char _type[30] )
    {
        degrees = _deg;
        minutes = _min;
        strcpy(direction, _dir);
        strcpy(type , _type);
    }

    void getAngle()
    {
        cout << "Enter type: ";
        this->setType();
        cout << "Enter degrees: ";
        this->setDegree();
        cout << "Enter minutes: ";
        this->setMinutes();
        cout << "Enter direction: ";
        this->setDirection();
    }

    void displayAngle()
    {
        cout << degrees << "\xF8" << minutes << "' " << direction;
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
            else if (strcmp(type, "Latitude") == 0) {
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


int main()
{
    angle lat(17, 31.5, "S" , "Latitude");

    int flag = 1;

    while(flag != 0)
    {
        lat.getAngle();
        lat.displayAngle();
        cout << "\nDo you want to continue? 0 if no any other key if yes :";
        cin>> flag;
    }

    return 0;
}
