#pragma once
#include <string>
#include <queue>
#include "PrintJob.h"
using namespace std;

class PrintQueue
{
public:
	//Constructor
	PrintQueue();
	
	//Accessors
	int GetWaitingTime();

	//State Mutators
	void SetWaitingTime(int waitingTime);
	void SetBusy(bool newState = true);
	void readData(string fileName);

	//Queue Mutators
	void removeJob();
	void addJob(PrintJob newJob);
	void sort();

private:
	queue<PrintJob> pendingJobs;
	vector<PrintJob> activeJobs;
	int pastJobs = 0;
	int currentJobs = activeJobs.size();
	int waitingTime = 0;
	bool busy;
};

