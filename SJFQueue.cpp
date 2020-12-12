#include "SJFQueue.h"
#include <iostream>

void SJFQueue::AddJob(PrintJob newJob) {
	int jobTime = newJob.GetServiceTime();
	if ( (activeJobs.empty()) || (jobTime >= activeJobs.back().GetServiceTime()) ){
		PrintQueue::AddJob(newJob);
	}
	else if (jobTime <= activeJobs.front().GetServiceTime()) {
		activeJobs.push_front(newJob);
	}
	else {
		for (list<PrintJob>::iterator itr = activeJobs.begin(); next(itr) != activeJobs.end(); itr++) {
			if ((itr->GetServiceTime() >= jobTime) && (jobTime < next(itr)->GetServiceTime())) {
				activeJobs.insert(next(itr), newJob);
				SetWaitingTime(jobTime);
			}
		}
	}
}