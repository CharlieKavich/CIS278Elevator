#ifndef ELEVATOR_H
#define ELEVATOR_H

#include <string>
#include <vector>

using namespace std;
class Elevator {
    private:
        int CurrentFloor = 2;
        int Destination;

    public:
    Elevator();
    void CallLift(string direction);

    int GetCurrentFloor();
    int GetDestination();
    void SetCurrentFloor(int floor);
    void SetDestination(int floor);

};

#endif