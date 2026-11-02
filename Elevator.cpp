#include "Elevator.h"

mutex Elevator::elMtx;
vector<thread> Elevator::lifts;

Elevator::Elevator() {
    CurrentFloor = 2;
}

Elevator::Elevator(int startingFloor, int totalFloors)
{
    this->totalFloors = totalFloors;
    CurrentFloor = startingFloor;

}
void Elevator::formatting(int row, const string& text)
{
    ostringstream out;
    out << "\0337" << "\033[" << row << ";1H" << "\033[2K" << text << "\0338";
    cout << out.str() << flush; 

}

void Elevator::floorReading(vector<Elevator>& shafts)
{
    unsigned int i;
    ostringstream line;
    line << "Elevator floor reading:";
    for(i = 0; i < shafts.size(); i ++)
    {
        line << setw(6) << shafts.at(i).GetCurrentFloor(); 
    }
    formatting(1, line.str());
}
void Elevator::liftPriority(int userFloor, vector<Elevator>& shafts, int targetLevel)
{
    lock_guard<mutex> lock(elMtx);
    int shaft;
    unsigned int i;
    Elevator* active = nullptr;

    for(i = 0; i < shafts.size(); i ++)
    {
        if(shafts.at(i).GetCurrentFloor() != shafts.at(i).GetDestination())
        {
            continue;
        }
        if(active == nullptr || (abs(shafts.at(i).GetCurrentFloor() - userFloor) < abs(active->GetCurrentFloor() - userFloor)))
        {
            active = &shafts.at(i);
            shaft = i;
            formatting(2, "Call from level " + to_string(userFloor) +  " to level " + to_string(targetLevel) + " on car " + to_string(i + 1) + ".");
        }
    }
    if(active == nullptr)
    {
        formatting(2, "Random Call unsuccessful, all elevators occupied.");
        return;
    }
    
    active->destination = userFloor;
    thread t1(&Elevator::callLift, active, ref(shafts), targetLevel, shaft);
  
    lifts.push_back(move(t1));


}

void Elevator::callLift(vector<Elevator>& shafts, int targetFloor, int shaft)
{
    unique_lock<mutex> lock(elMtx);
    
    int increment;
    if(CurrentFloor - destination > 0)
    {
        increment = -1;
    }
    else
    {
        increment = 1;
    }
    
    //The timing about to be used comes from the average elevator speed being around 0.5 m/s and the average height between floors being bout 5 meters.

    while(CurrentFloor != destination)

    {
        lock.unlock();
        this_thread::sleep_for(chrono::seconds(2));
        lock.lock();
        
        
        CurrentFloor += increment;

        floorReading(shafts);
    }
    destination = targetFloor;
    formatting(3, "Doors opening on shaft: " + to_string(shaft + 1));
    lock.unlock();
    this_thread::sleep_for(chrono::seconds(15));
    lock.lock();
    formatting(3, "Doors closing on shaft: " + to_string(shaft + 1));
   
    if(CurrentFloor - destination > 0)
    {
        increment = -1;
    }
    else
    {
        increment = 1;
    }
    
    while(CurrentFloor != destination)

    {
        lock.unlock();
        this_thread::sleep_for(chrono::seconds(2));
        lock.lock();
        
        
        CurrentFloor += increment;

        floorReading(shafts);
    }
    

}

int Elevator::GetCurrentFloor()
{
    return CurrentFloor;
}
int Elevator::GetDestination()
{
    return destination;
}
void Elevator::SetDestination(int floor)
{
    destination = floor;
}

int Elevator::randomToN(int n)
{
    lock_guard<mutex> lock(elMtx);
    return rand() % n + 1;
}
