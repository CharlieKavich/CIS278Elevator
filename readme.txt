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