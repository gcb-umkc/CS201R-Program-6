// Program 6.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include "PrintQueue.h"
#include "Clock.h"
using namespace std;

void runSimulation(PrintQueue test) {

}

int main()
{
    cout << "Beginning FIFO Simulation" << endl;
    //Label the output so that it is understandable
    //Not a realistic simulation of a print business
    //The general pattern should be SJF - shortest
    //Priority Queue will be similar to the FIFO queue

    PrintQueue FIFO = PrintQueue();
    FIFO.readData("Program6Data.txt");
    Clock newClock = Clock();
    while (!FIFO.isEmpty() || newClock.GetTime() <= 100) {
        if (!FIFO.isBusy()) {
            //If the queue is not busy, add another job to the queue
            FIFO.AddJob();
        }
        else {
            //Decrement the waiting time
            FIFO--;
        }

        //Increase the number of ticks
        cout << newClock.GetTime() << endl;
        newClock++;
    }

    cout << "Beginning SJF Simulation" << endl;

    cout << "Beginning FIFO Simulation" << endl;
}

