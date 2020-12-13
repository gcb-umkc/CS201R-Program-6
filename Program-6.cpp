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

//Main function, calls the simulation functions
int main()
{
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

//Statistic Variables to hold variables
struct statistic {
    int pastJobs = 0;
    int longestWait = 0;
    int shortestWait = 999999;
    int totalWaiting = 0;
};

//Updates the statistic struct given a waiting time
void updateStatistic(statistic& input, int waitingTime) {
    input.totalWaiting += waitingTime;
    //Updates the longest wait
    if (waitingTime > input.longestWait) {
        input.longestWait = waitingTime;
    }
    //Shortest wait
    if (waitingTime < input.shortestWait) {
        input.shortestWait = waitingTime;
    }
    input.pastJobs += 1;
}

void reportStatistics(statistic category) {
    cout << setfill('.') << "Total Jobs" << setw(36) << category.pastJobs << " jobs " << endl;
    cout << "Shortest Wait" << setw(30) << category.shortestWait << " minutes " << endl;
    cout << "Average Wait" << setw(31) << category.totalWaiting / (category.pastJobs + 0.0) << " minutes " << endl;
    cout << "Longest Wait" << setw(31) << category.longestWait << " minutes " << endl;
    cout << "Total Wait" << setw(33) << category.totalWaiting << " minutes " << endl;
}

//Main Function that simulates queuing times
void runSimulation(string dataFile, PrintQueue* printer) {
    //Input data
    queue<PrintJob> newJobs;
    readData(dataFile, newJobs);

    //Statistics Structs
    statistic admin;
    statistic faculty;
    statistic student;

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
                int waitingTime = ticks - tempJob.GetArrival();
                
                //Updates statistics for the appropriate category
                switch (tempJob.GetType()){
                case 'A':
                    updateStatistic(admin, waitingTime);
                    break;
                case 'F':
                    updateStatistic(faculty, waitingTime);
                    break;
                case 'S':
                    updateStatistic(student, waitingTime);
                    break;
                };
            }
        }
        else {
            //Decrement the waiting time and check if busy
            printer->update();
        }
        //Increase the number of ticks
        ticks++;
    }

    //Reports the statistics and the total wait
    cout << "Admin: " << endl;
    reportStatistics(admin);
    cout << endl;

    cout << "Faculty: " << endl;
    reportStatistics(faculty);
    cout << endl;

    cout << "Student: " << endl;
    reportStatistics(student);

    cout << endl;
    int totalJobs = student.pastJobs + faculty.pastJobs + admin.pastJobs;
    int totalWaiting = student.totalWaiting + faculty.totalWaiting + admin.totalWaiting;
    cout << "Total Queue Jobs: " << totalJobs << endl;
    cout << "Total Queue Wait: " << totalWaiting << " minutes " << endl;
    cout << "Average Queue Wait: " << (totalWaiting) / (totalJobs + 0.0) << " minutes " << endl;
    cout << endl;
}
