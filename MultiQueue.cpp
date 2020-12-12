#include "MultiQueue.h"

//Adds a new job to a multilevel queue
void MultiQueue::AddJob(PrintJob newJob) {
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
    };

    //Updates waiting time based on priority
    if (activeJobsAdmin.size() == 0) {
        if (activeJobsFaculty.size() == 0) {
            if (!activeJobsStudent.empty()) {
                SetWaitingTime(activeJobsStudent.front().GetServiceTime());
            }
        }
        else {
            if (!activeJobsFaculty.empty()) {
                SetWaitingTime(activeJobsFaculty.front().GetServiceTime());
            }
        }
    }
    else {
        if (!activeJobsAdmin.empty()) {
            SetWaitingTime(activeJobsAdmin.front().GetServiceTime());
        }
    }
}

//Removes a job based on level(admin, faculty, student), removing from highest first
PrintJob MultiQueue::RemoveJob() {
    PrintJob tempJob;
    //If the admin has no more active jobs, then
    if (activeJobsAdmin.size() == 0) {
        //Check if faculty has no more active jobs, then
        if (activeJobsFaculty.size() == 0) {
            //Do the student jobs
            tempJob = activeJobsStudent.front();
            activeJobsStudent.pop_front();
        }
        //Otherwise do the faculty jobs
        else {
            tempJob = activeJobsFaculty.front();
            activeJobsFaculty.pop_front();
        }
    }
    //Otherwise do the administrator jobs
    else {
        tempJob = activeJobsAdmin.front();
        activeJobsAdmin.pop_front();
    }

    //Return job handled
    return tempJob;
}

//Calculates sum of all active job queues - inefficient method
int MultiQueue::GetNumJobs() {
	int tempTotal = 0;
	tempTotal += activeJobsAdmin.size();
	tempTotal += activeJobsFaculty.size();
	tempTotal += activeJobsStudent.size();
	return tempTotal;
}
