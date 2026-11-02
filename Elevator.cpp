#include "Elevator.h"

Elevator::Elevator() {
    CurrentFloor = 2;
}

Elevator::Elevator(int startingFloor, int totalFloors)
{
    this->totalFloors = totalFloors;
    CurrentFloor = startingFloor;
}
void Elevator::liftPriority(int userFloor, vector<Elevator> shafts)
{
    unsigned int i;
    Elevator active = shafts.at(0);

    for(i = 0; i < shafts.size(); i ++)
    {
        if(abs(shafts.at(i).GetCurrentFloor() - userFloor) < abs(active.GetCurrentFloor() - userFloor))
        {
            active = shafts.at(i);
        }
    }

}

void Elevator::callLift(int userFloor, Elevator active)
{
    active.SetDestination(userFloor);
    

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
    return rand() % n + 1;
}
