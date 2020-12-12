#include "PrintJob.h"
#include <cmath>
using namespace std;

//Default constructor
PrintJob::PrintJob() {}

//Creates print job with classification and number of pages
PrintJob::PrintJob(int arrivalTime, char type, int pages) {
	this->arrivalTime = arrivalTime;
	this->type = type;
	this->pages = pages;
	this->serviceTime = this->GetTime();
}

//Calculates the service time from the type and the number of pages
int PrintJob::GetTime() {
	if (serviceTime) {
		//Divides by float 150.0 to keep fractions
		serviceTime = round(pages / 150.0 + 1);
	}
	return serviceTime;
}

//Returns the arrival time of the job
int PrintJob::GetArrival() {
	return arrivalTime;
}

//Returns the type of print job
char PrintJob::GetType() {
	return type;
}

//Returns the number of pages
int PrintJob::GetPages() {
	return pages;
}

int PrintJob::GetServiceTime() {
	return serviceTime;
}