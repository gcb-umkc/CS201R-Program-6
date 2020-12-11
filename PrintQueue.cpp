#include "PrintQueue.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

//Reads data from a file to the pending jobs
void PrintQueue::readData(string fileName) {
	ifstream input(fileName);

	char type;
	int time, pages;
	while (input.good()) {
		input >> time >> type >> pages;

		PrintJob newJob = PrintJob(type, pages);
		pendingJobs.emplace(time, newJob);
	}

	input.close();
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
PrintQueue PrintQueue::operator--(int) {
	if (waitingTime == 0) {
		this->busy = false;
	}
	else {
		waitingTime -= 1;
	}
	return *this;
}

//Returns if the print queue is busy or not
bool PrintQueue::isBusy() {
	if (waitingTime == 0) {
		return true;
	}
	else {
		return false;
	}
}

//Checks if both the pending jobs and active jobs are empty
bool PrintQueue::isEmpty() {
	if ((this->GetNumJobs() == 0) && (pendingJobs.size() == 0)) {
		return true;
	}
	else {
		return false;
	}
}


//Increments the waiting time
void PrintQueue::updateWait()
{
	//TODO FIFO Queue
}

//Pushes to the back for a job
void PrintQueue::AddJob() {
	//TODO FIFO Queue
}

//Pops from the front
void PrintQueue::RemoveJob() {
	pastJobs += 1;
	//TODO FIFO Queue
}

//Returns the number of jobs
int PrintQueue::GetNumJobs() {
	//TODO FIFO Queue
	return 0;
}

//Prints out the pending jobs
void PrintQueue::DisplayPending() {
	for (auto& x : pendingJobs) {
		cout << "Ticks: " << x.first << " Type: " << x.second.GetType() << " Pages: " << x.second.GetPages() << endl;
	}
}
