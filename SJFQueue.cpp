#include "SJFQueue.h"
#include <iostream>

//Adds a new job to a SJF queue, inserts based on service time of job
void SJFQueue::AddJob(PrintJob newJob) {
	int jobTime = newJob.GetServiceTime();

	//If the queue is empty or if the back is smaller, push to back
	if ( (activeJobs.empty()) || (jobTime >= activeJobs.back().GetServiceTime()) ){
		activeJobs.push_back(newJob);
	}
	//If the job is smaller than the front, add to front
	else if (jobTime <= activeJobs.front().GetServiceTime()) {
		activeJobs.push_front(newJob);
	}
	//Otherwise, adds somewhere in between
	else {
		for (list<PrintJob>::iterator itr = activeJobs.begin(); next(itr) != activeJobs.end(); itr++) {
			//Inserts the job where it fits inbetween the iterator and the next node
			if ((itr->GetServiceTime() >= jobTime) && (jobTime < next(itr)->GetServiceTime())) {
				activeJobs.insert(itr, newJob);
				break;
			}
		}
	}

	//If the queue is not empty, then set the front service time to the waiting time
	if (!activeJobs.empty()) {
		SetWaitingTime(activeJobs.front().GetServiceTime());
	}
}