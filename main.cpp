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
    int userFloor = 2;
    bool inerror;
    bool masterloop = true;
    cout << "Current floor: " << lift.GetCurrentFloor() << endl;
    cout << "Welcome to the Empire State Building." << endl << endl;
    while(masterloop)
    {
        inerror = true;
        while(inerror)
        {
        
            cout << "Would you like to call an elevator? (Yes/No)" << endl;
            cin >> in;
            if(lower(in) == "yes")
            {
                
                if(userFloor != 1 && userFloor != 102)
                {
                    while(inerror)
                    {
                        cout << "Would you like to go up or down? (Up/Down)" << endl;
                        cin >> in;
                        if(!(lower(in) == "up" || lower(in) == "down"))
                        {
                            cout << "Please double check your input, it should be (Up/Down). Thanks!" << endl;
                        }
                        else
                        {
                            inerror = false;
                        }
                    }
                }
                cout << "Calling the elevator." << endl;;
                inerror = false;
            }
            else if(lower(in) == "no")
            {
                cout << "Take your time and enjoy your time on this floor!" << endl;
                inerror = false;
                masterloop = false;
            }
            else
            {
                cout << "Please double check your input, it should be (Yes/No). Thanks!" << endl;
            }
      
        }

        
    }
    return 0;
}