#ifndef ELEVATOR_H
#define ELEVATOR_H
#include <cmath>
#include <string>
#include <vector>

using namespace std;
class Elevator {
    private:
        int CurrentFloor;
        int destination;
        int totalFloors;
        void callLift(int userFloor, Elevator active);

    public:
    Elevator();

    Elevator(int startingFloor, int totalFloors);

    static int randomToN(int n);
    
    static void liftPriority(int userFloor, vector<Elevator> shafts);

    int GetTotalFloors();

    void SetTotalFloors(int floors);

    int GetCurrentFloor();

    int GetDestination();

    void SetCurrentFloor(int floor);

    void SetDestination(int floor);

};

#endif