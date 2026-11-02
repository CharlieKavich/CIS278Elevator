#include <string>
#include <iostream>
#include <limits>
#include <random>
#include<chrono>
#include <thread>
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


void generateEnvironment(vector<Elevator>& env, int count, int floors)
{
    unsigned int i;
    for(i = 0; i < count; i++)
    {
        int current = Elevator::randomToN(floors);
        Elevator elevator(current, floors);
        env.push_back(elevator);
    }
}

void simulation(vector<Elevator> shafts)
{
    unsigned int i;
    for(i = 0; i < shafts.size(); i ++)
    {
        cout << shafts.at(i).GetCurrentFloor() << " "; 
    }
}

int main(){
    vector<Elevator> shafts;
    int i;
    int totaFloors;
    int userFloor = 2;
    int elevatorCount;
    string in;
    bool inerror = true;
    bool masterloop = true;
    cout << "Welcome to the Elevator simulation config." << endl;
    while(inerror)
    {
        cout << "Please enter the number of floor you would like between 5 and 20: " << endl;
        cin >> totaFloors;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "It seems like your input was invalid. ";
            continue;
        }
        if(totaFloors < 21 && totaFloors > 4)
        {
            inerror = false;
        }
        else
        {
            cout << "It seems like your input was invalid. ";
        }
    }
    cout << "Input confirmed: " << totaFloors << " floors." << endl;
    inerror = true;
    while(inerror)
    {
        cout << "How many elevator shafts would you like to simulate? Pick a quantity between 1 and 4: " << endl;
        cin >> elevatorCount;
        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "It seems like your input was invalid. ";
            continue;
        }
        if(elevatorCount < 5 && elevatorCount > 0)
        {
            inerror = false;
        }
        else
        {
            cout << "It seems like your input was invalid. ";
            elevatorCount = -1;
        }
    }
    cout << "Input confirmed: " << elevatorCount << " shafts." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Generating simulation..." << endl;
    generateEnvironment(shafts, elevatorCount, totaFloors);
    this_thread::sleep_for(chrono::seconds(4));
    cout << "Generated. Please press enter to continue" << endl; 

    simulation(shafts);

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