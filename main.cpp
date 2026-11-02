

#include "Elevator.h"
#include "all.h"


using namespace std;

atomic<bool> running(true);

string lower(string input)
{
    int i;
    for(i = 0; i < input.length(); i++)
    {
        input.at(i) = tolower(input.at(i));
    }
    return input;
}

void RandomElevatorCalls(vector<Elevator>& shafts, int floors)
{
    while(running)
    {
        int start = Elevator::randomToN(floors);
        int end = Elevator::randomToN(floors);
        this_thread::sleep_for(chrono::seconds(15));
        if(!running)
        {
            break;
        }
        
        Elevator::liftPriority(Elevator::randomToN(floors), shafts, Elevator::randomToN(floors));
    }
}

void generateEnvironment(vector<Elevator>& env, int count, int floors)
{
    unsigned int i;
    for(i = 0; i < count; i++)
    {
        int current = Elevator::randomToN(floors);
        Elevator elevator(current, floors);
        env.push_back(elevator);
        env.at(i).SetDestination(current);
    }
}

void simulation(vector<Elevator>& shafts)
{
    
    
    Elevator::liftPriority(1, shafts, 20);


}

int main(){
    srand(time(nullptr));
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
    cout << "\033[2J" << "\033[4;r" << "\033[4;1H" << flush;
    {
        lock_guard<mutex> lock(Elevator::elMtx);

        Elevator::floorReading(shafts);
    }
    RandomElevatorCalls(shafts, totaFloors);

    

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