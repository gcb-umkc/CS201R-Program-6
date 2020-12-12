#include "MultiQueue.h"


PrintJob MultiQueue::RemoveJob() {
    PrintJob tempJob;
    if (activeJobsAdmin.size() == 0) {
        if (activeJobsFaculty.size() == 0) {
            tempJob = activeJobsStudent.front();
            activeJobsStudent.pop_front();
        }
        else {
            tempJob = activeJobsFaculty.front();
            activeJobsFaculty.pop_front();
        }
    }
    else {
        tempJob = activeJobsAdmin.front();
        activeJobsAdmin.pop_front();
    }

    return tempJob;
}

void MultiQueue::AddJob(PrintJob newJob) {
    switch (newJob.GetType())
    {
    case 'A':
        activeJobsAdmin.push_back(newJob);
        break;
    case 'F':
        activeJobsFaculty.push_back(newJob);
        break;
    case 'S':
        activeJobsStudent.push_back(newJob);
        break;
    default:
        break;
    };
}

int MultiQueue::GetNumJobs() {
	int tempTotal = 0;
	tempTotal += activeJobsAdmin.size();
	tempTotal += activeJobsFaculty.size();
	tempTotal += activeJobsStudent.size();
	return tempTotal;
}
