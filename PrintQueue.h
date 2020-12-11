#pragma once
#include <string>
#include <list>
#include <map>
#include "PrintJob.h"
using namespace std;

class PrintQueue
{
public:
	//Constructor
	PrintQueue() {};
	
	//State Accessors
	int GetWaitingTime();
	bool isEmpty();
	bool isBusy();

	//State Mutators
	void SetWaitingTime(int waitingTime);
	void readData(string fileName);
	PrintQueue operator--(int);

	//Queue Mutators
	virtual void RemoveJob();
	virtual void AddJob();
	virtual int GetNumJobs();
	virtual void updateWait();
	
	//Other Functions
	void DisplayPending();

private:
	//Functionality
	map<int, PrintJob> pendingJobs;
	list<PrintJob> activeJobs;
	int waitingTime = 0;
	bool busy = false;

	//Statistics;
	int totalWaitingAdministrators = 0;
	int totalWaitingFaculty = 0;
	int totalWaitingStudents = 0;
	int longestWait = 0;
	int pastJobs = 0;
};

