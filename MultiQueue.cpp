#include "MultiQueue.h"

//Removes a job based on level(admin, faculty, student), removing from highest first
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

//Adds a new job to a multilevel queue
void MultiQueue::AddJob(PrintJob newJob) {
    SetWaitingTime(newJob.GetServiceTime());

    //Adds to queues based on the job type
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

//Calculates sum of all active job queues - inefficient method
int MultiQueue::GetNumJobs() {
	int tempTotal = 0;
	tempTotal += activeJobsAdmin.size();
	tempTotal += activeJobsFaculty.size();
	tempTotal += activeJobsStudent.size();
	return tempTotal;
}
