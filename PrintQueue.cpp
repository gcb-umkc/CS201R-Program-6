#include "PrintQueue.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Default constructor
PrintQueue::PrintQueue() {
	busy = false;
	waitingTime = 0;
}

//Sets the time the print queue will be busy for
void PrintQueue::SetWaitingTime(int waitingTime) {
	this->waitingTime = waitingTime;
}

//Returns the length of time you have to weight
int PrintQueue::GetWaitingTime() {
	return waitingTime;
}

//Decrements the waiting time by one minute
void PrintQueue::update() {
	if (waitingTime == 0) {
		this->busy = false;
	}
	else {
		waitingTime -= 1;
	}
}

//Returns if the print queue is busy or not
bool PrintQueue::isBusy() {
	if (waitingTime == 0) {
		return false;
	}
	else {
		return true;
	}
}

//Virtual Functions

//Pushes to the back for a job
void PrintQueue::AddJob(PrintJob newJob) {
	activeJobs.push_back(newJob);
	waitingTime = activeJobs.front().GetServiceTime();
}

//Pops from the front
PrintJob PrintQueue::RemoveJob() {
	PrintJob temp = activeJobs.front();
	activeJobs.pop_front();
	return temp;
}

//Returns the number of jobs
int PrintQueue::GetNumJobs() {
	return activeJobs.size();
}