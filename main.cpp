#include <string>
#include <iostream>
#include "Elevator.h"
#include <cctype>


using namespace std;


string lower(string input)
{
    int i;
    for(i = 0; i < input.length(); i++)
    {
        input.at(i) = tolower(input.at(i));
    }
    return input;
}
int main(){
    Elevator lift;
    string in;
    bool inerror = true;
    bool masterloop = true;
    cout << "Current floor: " << lift.GetCurrentFloor() << endl;
    cout << "Welcome to the Empire State Building." << endl << endl;
    while(masterloop)
    {
        while(inerror)
        {
        if(lift.GetCurrentFloor() != 1 && lift.GetCurrentFloor() != 40)
        {
            cout << "Would you like to call an elevator? (Yes/No)" << endl;
            cin >> in;
            if(lower(in) == "yes")
            {
                inerror = false;
            }
            else if(lower(in) == "no")
            {
                cout << "Take your time and enjoy your time on this floor!" << endl;
                inerror = false;
                masterloop = false;
            }
        }
        }
        
    }
    return 0;
}