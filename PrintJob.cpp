#include "PrintJob.h"
using namespace std;

//Creates print job with classification and number of pages
PrintJob::PrintJob(char type, int pages) {
	this->type = type;
	this->pages = pages;
	this->serviceTime = this->GetTime();
	this->waitingTime = 0;
}

//Returns the service time
int PrintJob::GetTime() {
	if (serviceTime) {
		//TODO: time calculations
		serviceTime = pages;
	}
	return serviceTime;
}

//Returns the type of print job
char PrintJob::GetType() {
	return type;
}

//Returns the number of pages
int PrintJob::GetPages() {
	return pages;
}

PrintJob PrintJob::operator++(int) {
	waitingTime += 1;
	return *this;
}