#ifndef ELEVATORH
#define ELEVATORH

class Elevator {
    private:
        int CurrentFloor = 1;
        int Destination;

    public:

    void CallLift(string direction);

    int GetCurrentFloor();
    int GetDestination();
    void SetCurrentFloor(int floor);
    void SetDestination(int floor);

}