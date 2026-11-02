#ifndef ELEVATOR_H
#define ELEVATOR_H
#include "all.h"


using namespace std;
class Elevator {
    private:
        int CurrentFloor;
        int destination;
        int totalFloors;
        
        void callLift(vector<Elevator>& shafts, int targetFloor, int shaft);
        

    public:
    Elevator();

    Elevator(int startingFloor, int totalFloors);
    
    
    static void formatting(int row, const string& text);
    static void floorReading(vector<Elevator>& shafts);
    static int randomToN(int n);
    
    static void liftPriority(int userFloor, vector<Elevator>& shafts, int targetLevel);

    static mutex elMtx;

    static vector<thread> lifts;

    int GetTotalFloors();

    void SetTotalFloors(int floors);

    int GetCurrentFloor();

    int GetDestination();

    void SetCurrentFloor(int floor);

    void SetDestination(int floor);

};

#endif