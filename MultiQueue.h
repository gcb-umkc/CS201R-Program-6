#pragma once
#include <list>
#include "PrintJob.h"
#include "PrintQueue.h"
class MultiQueue :
    public PrintQueue
{
public:
	void AddJob(PrintJob newJob);
	PrintJob RemoveJob();
	int GetNumJobs();

private:
	list<PrintJob> activeJobsAdmin;
	list<PrintJob> activeJobsFaculty;
	list<PrintJob> activeJobsStudent;
};

