// George Bennett
// gcbz9k@mail.umkc.edu
// 3/12/2020
// CS201R Program 6

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <queue>

#include "PrintQueue.h"
#include "SJFQueue.h"
#include "MultiQueue.h"
using namespace std;

//Helper function headers
void readData(string fileName, queue<PrintJob>& pendingJobs);
void runSimulation(string dataFile, PrintQueue* printer);


int main()
{
    //Label the output so that it is understandable
    //Not a realistic simulation of a print business
    //The general pattern should be SJF - shortest
    //Priority Queue will be similar to the FIFO queue

    cout << setw(35) << right << "Queue Simulations: " << endl;
    string data = "Program6Data.txt";

    cout << "Results of First In, First Out Simulation" << endl;
    
    PrintQueue* FIFO2 = new PrintQueue();
    runSimulation(data , FIFO2);
    
    cout << endl << "Results of Shortest Job First Simulation" << endl;
    PrintQueue* second = new SJFQueue();
    runSimulation(data, second);

    cout << endl << "Results of Multi-level Queue Simulation" << endl;
    PrintQueue* third = new MultiQueue();
    runSimulation(data, third);
}

//Reads data from a file to the pending jobs
void readData(string fileName, queue<PrintJob>& pendingJobs) {
    ifstream input(fileName);

    char type;
    int time, pages;
    while (input.good()) {
        input >> time >> type >> pages;

        PrintJob newJob = PrintJob(time, type, pages);
        pendingJobs.push(newJob);
    }

    input.close();
}

//Main Function that simulates queuing times
void runSimulation(string dataFile, PrintQueue* printer) {
    //Statistic Variables
    int pastJobs = 0;
    int longestWait = 0;
    int totalWaitingAdmin = 0;
    int totalWaitingFaculty = 0;
    int totalWaitingStudent = 0;

    //Input Data
    queue<PrintJob> newJobs;
    readData(dataFile, newJobs);

    //Main Simulation Loop
    int ticks = 0;
    while (!(newJobs.empty() && printer->GetNumJobs() == 0)) {
        //Takes in new jobs if the time is right
        while ((newJobs.size() > 1) && (newJobs.front().GetArrival() == ticks) && (ticks < 480)) {

            //Adds the new job and removes the item from the pending queue
            printer->AddJob(newJobs.front());
            newJobs.pop();

            //Handles the last item in the queue
            if (newJobs.size() == 1) {
                newJobs.pop();
            }
        }

        //Processes the jobs if the printer is not busy
        if (!printer->isBusy()) {
            //If there is a last job, removes it assuming that the time frame has past for it
            if (printer->GetNumJobs() > 0) {
                PrintJob tempJob = printer->RemoveJob();

                //Updates the waiting time statistics
                int waitingTime = ticks - tempJob.GetArrival();
                if (waitingTime > longestWait) {
                    longestWait = waitingTime;
                }
                //Adds waiting time to appropriate category
                switch (tempJob.GetType())
                {
                case 'A':
                    totalWaitingAdmin += waitingTime;
                    break;
                case 'F':
                    totalWaitingFaculty += waitingTime;
                    break;
                case 'S':
                    totalWaitingStudent += waitingTime;
                    break;
                };
                //Increments total job number
                pastJobs++;
            }
        }
        else {
            //Decrement the waiting time and check if busy
            printer->update();
        }

        //Increase the number of ticks
        ticks++;
    }

    //Reports the statistics
    int totalWait = totalWaitingAdmin + totalWaitingFaculty + totalWaitingStudent;
    cout << setfill('.') << "Total Jobs" << setw(36) << pastJobs << " jobs " << endl;
    cout << "Longest Wait" << setw(31) << longestWait << " minutes " << endl;
    cout << "Total Administrator" << setw(24) << totalWaitingAdmin << " minutes " << endl;
    cout << "Total Faculty" << setw(30) << totalWaitingFaculty << " minutes " << endl;
    cout << "Total Student" << setw(30) << totalWaitingStudent << " minutes " << endl;
    cout << "Total Wait" << setw(33) << totalWait << " minutes " << endl;
}