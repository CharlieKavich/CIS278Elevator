Paste the following into vs code terminal to tun on mac:
clang++ -std=gnu++14 -g main.cpp Elevator.cpp -o main
./main

Paste the following into vscode terminal to run on windows:
 g++ -std=c++17 -g main.cpp Elevator.cpp -o main
>> ./main

Team members: Charlie Kavich

Features:
    Dynamically allocate Elevator objects
    Call Elevators
    Live display of all elevator floors
    Live display with status updates like specific elevator's doors opening
    Random calls to elevators to simulate random people in a building calling elevators
    Elevator calls prioritizing the nearest non moving elevator

Gui explanation:
    For best explanation watch the following video:
    https://www.youtube.com/watch?v=uy2cRQ70caI

    Otherwise, after initialization, the top row has a display of numbers that display the level of each elevator.
    The second displays whenever an elevator is called either by the random funciton or the user
    The third line displays when the doors open and close on specific elevators.

    Everything else is part of the user input output loop.


