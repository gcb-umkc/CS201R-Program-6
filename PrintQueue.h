#pragma once
#include <string>
#include <list>
#include "PrintJob.h"
using namespace std;

class PrintQueue
{
public:
	//Default constructor
	PrintQueue();
	
	//State Accessors
	int GetWaitingTime();
	bool isBusy();

	//State Mutators
	void SetWaitingTime(int waitingTime);
	void update();

	//Queue Mutators
	virtual void AddJob(PrintJob newJob);
	virtual PrintJob RemoveJob();
	virtual int GetNumJobs();

protected:
	list<PrintJob> activeJobs;
	int waitingTime;
	bool busy;
};

