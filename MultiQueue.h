#pragma once
#include <list>
#include "PrintQueue.h"

class MultiQueue :
    public PrintQueue
{
public:
	//Queue Mutators
	void AddJob(PrintJob newJob);
	PrintJob RemoveJob();
	int GetNumJobs();

private:
	//Multilevel Queues
	list<PrintJob> activeJobsAdmin;
	list<PrintJob> activeJobsFaculty;
	list<PrintJob> activeJobsStudent;
};

